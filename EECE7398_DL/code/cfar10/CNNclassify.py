import os
import torch
import torchvision
import torchvision.transforms as transforms
from tqdm import tqdm
import math
import torch.optim as optim
import torch.optim.lr_scheduler as lr_scheduler
import matplotlib.pyplot as plt
import pylab
import numpy as np
from torch.autograd import Variable
import torch.nn as nn

import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(0)
torch.cuda.manual_seed(0)

batch_size = 100
learning_rate = 0.01
learning_rate_decay = 0.0005
momentum = 0.9
epoch_step = 25
max_epoch = 30

transform_train = transforms.Compose(
    [transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

transform_test = transforms.Compose(
    [transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

trainset = torchvision.datasets.CIFAR10(root='./data', train=True,
                                        download=False, transform=transform_train)
trainloader = torch.utils.data.DataLoader(trainset, batch_size=batch_size,
                                          shuffle=True, num_workers=8)

testset = torchvision.datasets.CIFAR10(root='./data', train=False,
                                       download=False, transform=transform_test)
testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size,
                                         shuffle=False, num_workers=8)


save_dir = "./save"
if not os.path.exists(save_dir):
    os.mkdir(save_dir)


def weights_init(m):
    if isinstance(m, nn.Conv2d):
        n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
        m.weight.data.normal_(0, math.sqrt(2./n))
    elif isinstance(m, nn.BatchNorm2d):
        m.weight.data.fill_(1)
        m.bias.data.zero_()

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(3,32,5)
        self.conv2 = nn.Conv2d(32,64,5)
        self.conv3 = nn.Conv2d(64,64,3)
        self.conv4 = nn.Conv2d(64,64,3)
        self.pool = nn.MaxPool2d(2,2)
        self.fc1 = nn.Linear(4*4*64,512)
        self.fc2 = nn.Linear(512,10)

    def forward(self,x):
        x = self.pool(F.relu(self.conv2(F.relu(self.conv1(x)))))
        x = self.pool(F.relu(self.conv4(F.relu(self.conv3(x)))))
        x = x.view(-1, 4*4*64)
        x = F.relu(self.fc1(x))
        x = self.fc2(x)

        return x

def train():
    net = Net()
    net.apply(weights_init)
    net.cuda()

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=learning_rate, momentum=0.9, weight_decay=learning_rate_decay)
    scheduler = lr_scheduler.StepLR(optimizer, step_size=epoch_step, gamma=0.5)

    test_accuracies = np.zeros(max_epoch)
    for epoch in range(max_epoch):  # loop over the dataset multiple times
        pbar = tqdm(trainloader)
        pbar.mininterval = 1 # update the processing bar at least 1 second
        
        net.train()
        running_loss, correct, total = 0.,0.,0.
        scheduler.step()
        
        for i, data in enumerate(pbar, 0):
            inputs, labels = data
            inputs, labels = Variable(inputs.cuda()), Variable(labels.cuda())
            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            
            #update
            running_loss = running_loss * (i/(i+1.)) + loss.data[0] * (1./(i+1.) )
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels.data).sum()
        print('\033[0;32m Statistics on epoch :%d learning rate: %f\033[0m' %(epoch, scheduler.get_lr()[0]))
        print('Train Loss : %f Train Accuracy: %f %%' % (running_loss, 100. * correct / total))

        
        #test
        net.eval()

        correct, total = 0., 0.
        for data in testloader:
            images, labels = data
            images = Variable(images.cuda())
            outputs = net(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels.cuda()).sum()

        print('Test Accuracy: \033[1;33m%f %%\033[0m' % (100. * correct / total))
        test_accuracies[epoch] = 100. * correct / total

    torch.save(net.state_dict(), './save/final2.pkl')

    #test accuracy
    correct, total = 0., 0.
    for data in testloader:
        images, labels = data
        images = Variable(images.cuda())
        outputs = net(images)
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels.cuda()).sum()

    print('Test Accuracy: \033[1;33m%f %%\033[0m' % (100. * correct / total))
    test_accuracies[epoch] = 100. * correct / total


def test(path = './save/final.pkl'):
    batch_size = 1
    datatest = torch.utils.data.DataLoader(testset, batch_size=batch_size,
                                         shuffle=False, num_workers=8)
    classes = ('plane', 'car', 'bird', 'cat',
           'deer', 'dog', 'frog', 'horse', 'ship', 'truck')
    new_net = Net()
    new_net.eval()
    new_net.load_state_dict(torch.load(path))
    new_net.cuda()
    count = 1
    for data,label in datatest:
        count += 1
        if count >= batch_size:
            break
    images = Variable(data.cuda())
    new_image = torch.reshape(images, (-1,3,32,32))
    outputs = new_net(new_image)
    _, predicted = torch.max(outputs.data, 1)
    for item in predicted:
        print(classes[item])


train()

test()