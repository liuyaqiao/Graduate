## Notes

Week 1

1/8

- motivation

    首先提出的是DNN，当DNN的层数增加后，一开始验证效果会提升，但随着深度继续增加，会出现performance的下降。这时候是因为有着更多的参数，出现了过拟合的现象。所以我们为了解决这个问题出现了CNN，它具有参数权值共享等优势。可以使网络层数更深，学到更多的特征。但是在网络不断加深的时候，出现了梯度弥散和梯度消失的问题（因为它们太小了，用求导的方法做的时候会消失）。这是提出了Resnet去解决这个梯度弥散的问题，但是在同样层数的Resnet和之前的传统DNN、CNN网络相比，Resnet不具有优越性，甚至是更低的准确度。所以，只有更深的网络才可以带来performance大幅度的提升，所以出现了Resnet101、Resnet152等。
    
- Criticism on Deep Learning

    1.  之前缺少对NN的数学研究，我们认为存在过多的local minimum，不容易找到真的的全局最优解。
    2.  NN的理论难以用我们现存的理论去解释。
    3.  不需要任何的domain knowledge，只是单纯的去收集数据、训练和验证。
    4. 过于依赖GPU等设备。

PCA是autoencoder的一种特殊形式。

1/11

在CNN出现之前，都是DNN占据了主导地位，网络含有很多的参数，这也是过拟合的原因。当CNN出现之后，仍然是FC层的参数占据了大多数，它占据了绝大多数的计算能力。知道Resnet的出现，才稍微缓解了这一情况。

现在神经网络都做的很大，要求的计算能力很大。所以，我们要考虑通过压缩的方法把参数变少，使得计算更快。这时有一个tricky的地方，我们对某一层做压缩或者其他操作之后，最好是通过重新训练全部网络的方法再去验证整个网络的性能，否则没有意义。

Overfit的原因现在看来有两方面：
1.参数带来的overfit
2.网络结构带来的overfit

换句话说，如果对一个网络不断压缩，结果仍然很好，但是generalization的效果不好，这里的原因就可能是当前的网络结构对当前数据集有很大的专一性。它非常适配当前的数据库，所以效果很好，但是至于其他数据库，它的效果就不是很好了。这也是overfit的一方面。

对于**alphago**来说，下采样或者其他方式采用没有任何物理意义。因为池化的本身目的就是要保留图像的部分特征，对于alphago这种选择的模型来说，池化没有任何意义。所以alphago中没有池化的概念。

Week 2

1/15

## Activation Layer:

我们需要加入激励层来添加非线性，这是神经网络中很重要的点。否则，如果只是线性模型，将不能解决很多问题。比如XOR。可以说，非线性是神经网络表现好的很重要的一个原因。

Relu

Sigmoid

Tanh

Relu的优势有两个：

1. 可以提供非线性
2. 带来sparsity，这是一个很好的性质。稀疏性可以减少参数之间的相互依赖关系，降低过拟合的风险。有一些类似于dropout的风险。
3. 不会出现梯度弥散(这也是sigmoid等relu函数出现的问题)

缺点：

1. 对初始化敏感
2. 0的位置不可导

Relu的几种变形：

1. soft relu
2. 2nd_relu
3. leaky relu

配合不同的dropout会表现的好，这是

不同的structure会更接近于使用不同的activation function，比如说RNN会关注一些于state有关的状态和取值，我们一般会使用sigmoid和tanh多一些。而一般CNN则会使用relu。

这里指出一下**sigmoid**的优势，适合用于与0/1取值、分类等问题上，并且对初始化不敏感。但是，它存在梯度消失的问题。

## supervised and unsupervised learning

no essenital gap! 唯一的区别就是label，他们所做的事情是一样的。

classification 和 regression

其实在本质上是相同的，我们都会得出一个分数，classification会输出最大分数对应的类。而regression直接会输出最大的分数。



## minimum question

saddle point

local minimum

Hessian Matrix

1/18

在training中出现的梯度消失和梯度爆炸：

因为网络太深，网络权值更新不稳定造成的，本质上是因为梯度反向传播中的连乘效应造成的。

在进行反向传播的时候会出现，考虑链式法则，第一层的权重更新会由之后每一层的权重的导数所决定。在网络足够深的时候，如果每一层的导数都大于1，那么这个值将会变得很大，那么第一层的权重就会变化很大，这就是梯度爆炸。而如果这个导数都小于1，这里将会无限接近哦于0，这就是梯度消失，这会给训练之中带来很多困难。

我们在使用sigmoid函数的时候，由于它的导数最大是0.25，而权值初始化的值一般也小于1，所以wx的值小于0.25，在网络加深的条件下，我们到达返回的变化量基本是0。针对普遍的这个问题，我们可以考虑用Relu激活函数，它的导数是1.

同时，我们考虑的一个比较好的方法是BN。Relu和Resnet也是从其他方面来解决这个问题。

Batch Normalization：

机器学习领域有个很重要的假设：假设训练数据和测试数据是满足相同分布的，这是通过训练数据获得的模型能够在测试集获得好的效果的一个基本保障。那BatchNorm的作用是什么呢？BatchNorm就是在深度神经网络训练过程中使得每一层神经网络的输入保持相同分布的。

BN的基本思想其实相当直观：因为深层神经网络在做非线性变换前的激活输入值（就是那个x=WU+B，U是输入）随着网络深度加深或者在训练过程中，其分布逐渐发生偏移或者变动，之所以训练收敛慢，一般是整体分布逐渐往非线性函数的取值区间的上下限两端靠近（对于Sigmoid函数来说，意味着激活输入值WU+B是大的负值或正值），所以这导致反向传播时低层神经网络的梯度消失，这是训练深层神经网络收敛越来越慢的本质原因，而BN就是通过一定的规范化手段，把每层神经网络任意神经元这个输入值的分布强行拉回到均值为0方差为1的标准正态分布，其实就是把越来越偏的分布强制拉回比较标准的分布，这样使得激活输入值落在非线性函数对输入比较敏感的区域，这样输入的小变化就会导致损失函数较大的变化，意思是这样让梯度变大，避免梯度消失问题产生，而且梯度变大意味着学习收敛速度快，能大大加快训练速度。

对于每个隐层神经元，把逐渐向非线性函数映射后向取值区间极限饱和区靠拢的输入分布强制拉回到均值为0方差为1的比较标准的正态分布，使得非线性变换函数的输入值落入对输入比较敏感的区域，以此避免梯度消失问题。

用一句话来总结，其实BN就是把隐层神经元激活输入从不拘一格的输入，变成均值是0、方差为1的正态分布。经过BN之后，大部分Activation的值会落入非线性函数的线性区，使其远离饱和区，这样可以加速训练收敛速度。

prediction中不需要bn层。

![BN](https://raw.githubusercontent.com/liuyaqiao/Learning-Note/master/BN.png)

BN层是在激活层之前加入，对于mini-batch的SGD，我们的变换公式就可以写成：

<a href="https://www.codecogs.com/eqnedit.php?latex=x^{(k)}&space;=&space;\frac{x^{(k)}&space;-&space;E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x^{(k)}&space;=&space;\frac{x^{(k)}&space;-&space;E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" title="x^{(k)} = \frac{x^{(k)} - E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" /></a>

如果只进行这样的变换会带来网络表达能力的下降，所以我们加入两个参数，这两个参数是通过学习得到：（因为它意味只利用了激活函数的线性部分，可能造成表达能力的下降。）

<a href="https://www.codecogs.com/eqnedit.php?latex=y^{(k)}&space;=&space;\gamma&space;^{(k)}x^{(k)}&space;&plus;&space;\beta^{(k)}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?y^{(k)}&space;=&space;\gamma&space;^{(k)}x^{(k)}&space;&plus;&space;\beta^{(k)}" title="y^{(k)} = \gamma ^{(k)}x^{(k)} + \beta^{(k)}" /></a>

所以BN为了保证非线性的获得，对变换后的满足均值为0方差为1的x又进行了scale加上shift操作(y=scale*x+shift)，每个神经元增加了两个参数scale和shift参数，这两个参数是通过训练学习到的，意思是通过scale和shift把这个值从标准正态分布左移或者右移一点并长胖一点或者变瘦一点，每个实例挪动的程度不一样，这样等价于非线性函数的值从正中心周围的线性区往非线性区动了动。核心思想应该是想找到一个线性和非线性的较好平衡点，既能享受非线性的较强表达能力的好处，又避免太靠非线性区两头使得网络收敛速度太慢。

[参考文献](https://www.cnblogs.com/guoyaohua/p/8724433.html)

week 3

1/22

- 我们为什么要选择softmax

1. 因为这里softmax易于训练，可以替代cross entropy。如果利用cross entropy, 后向传播是它的导数可能是1/y，在这个分母概率比较小的情况下，可能会出现overflow的情况，造成训练过程的报错。所以利用softmax函数来训练，就不会出现这样的问题。

2. 因为softmax同时考虑其他类别的得分，不会只考虑自己造成错误。

- Regurlarization

造成overfit的原因一般来说有两个：

1. model有太多的参数

2.有一些高次项的参数太大，它对整个模型的的影响太大。因为这个参数大，而且自变量的次数比较高，所以对整个函数走势的影响较大。所以我们想要引入的正则项应该是尽可能把这一项变小。

这里给出了L1、L2 Regurlarization的方法，他们分别着重解决了以上的两个问题：

L1的解具有稀疏化，所以它解决了参数过多的问题。而L2则是加入了惩罚项而是高次项参数值变小。

这里再说一下L0,L1和L2的关系和区别：

简单的来说，对于模型的参数向量而言，L0范数表示，参数向量中非零的元素的个数，L1范数表示向量中各个元素的绝对值之和，L2范数指的是各个元素的平方和然后求平方根。我们一般用范数来对模型进行约束：

如果使用L0优化，我们的目的就是让参数中不为0的数的数量尽量小。一般来说，求解这个问题是一个NP-hard问题。（因为这是一个最优化求解问题，需要使用到穷举和贪心的思想，而且矩阵是稀疏的，所以时间复杂度很大）

可以证明，L0和L1惩罚具有一致性，都可以使矩阵变得稀疏。可以[参考](https://github.com/liuyaqiao/Learning-Note/blob/master/Machine%20Learning/Algorithms/Logistic%20Regression.md)，这里用另一种方法来解释一下：

https://www.jianshu.com/p/4bad38fe07e6




- 后向传播的具体推导：

实际上在数值计算中，不需要知道这么多的公式法则，它会有更简便的方法去求。

- 对神经元和神经网络的理解：

神经元就是指一个带权重W和偏置B，以及激活方程f的一个单元 输入I和输出O的关系是 O = f(WI+B)

1/25

CNN

- DNN的结构主要由两个方面所决定：

1. Architecture: number of layers, type of layers, activation functions, connection of layers, number of size, stride of CNN kernel, numbers of neuron in FC, size and stride of Pooling layers

2. parameters: weights and bias

- MLP：多层感知器

至少含有一个隐藏层，的全连接网络。

- CNN

1. 注意一下conv计算的流程，有几个kernel对应这输出的feature map有几个channel。
2. 下一层的计算公式

conv：
fileer size = f * f
number of filters : k
stride : s

output size : A2 * B2 * C2

A2 = ceiling((A1 - f)/s + 1)
C2 = k

在进行pooling的计算时，也可以使用上面这个公式。


week 6

2/5

- 数值求导

使用电脑求导求的行，是数值形式的导数，而不是解析形式的导数；

所以对于y = max(x1,0)等特殊函数的求导时我们可以看作是这样：

if y = x1, dy/dx = 1; else dy/dx = 0

同样的我们relu和max pooingye可以做这样的处理。

- mini-batch 和 mini batch learning

我们要搞清mini batch, reshuffle, epoch, samples之间的关系；

我们所有的sample可以分成很多相同的小部分，每一个小的部分就相当于是一个batch；我们训练的流程是：首先把所有的样本经过reshuffle之后，形成batch。之后在一个batch上对每一个sample进行梯度的计算，我们取最后梯度的平均值成为最终的梯度更新的方向；之后再进行下一个batch的计算和更新；当计算完所有的batch之后，我们称为完成了一个eppch，之后再次进行reshuffle操作，重新划分batch；开始进行下一个epoch，直到我们要求的epoch数量。

mini-batch的batch_size受到gpu内存的影响。

- how to train a neural network:

Before training:
1. choose activation functions
2. Preprocess input data
3. Weight initalization
4. Choose regularization techniques
5. Check gradient evaluation using numerical methods

During training:
1. Monitor the training process
2. Choose the weight update method
3. Use cross-validation for hyper-parameter selection

After training:
Model ensembles for better accuracy

- Weight Initialization

首先看几个不合适的方法：

假设tanh

1. 全部初始化为0

正向传播的结果全是0，计算误差后进行反向传播，因为bp计算出的梯度是相同的，从而网络将变成一个完全对称的网络。同时，如果网络层数多雨2层，需要用到中间值的偏导，他们求出的结果将是0.

2. 初始化为small random numbers

经过几层之后，所有的neurons将会收敛为0. 导致我们的梯度也是0，无法进行有效的更新。

因为权重比较小，线性计算之后激活之后也很小；几层之后，神经元之后的输出值就会成为0；

3. 初始化为large random numbers

经过几层传播之后，所有neurons将会收敛到 +1 或 -1. 也会导致梯度是0，无法有效的训练。

所以我们需要一种方法，使得在神经元计算之后的值在激活函数合理的运算区域：

Xavier Initialization : 

它的目的是：尽可能的让输入和输出服从相同的分布，这样就能够避免后面层的激活函数的输出值趋向于0，这样使每一层的分布都接近于均值是0方差相同。所以，我们想办法使得他们的方差保持一致，这里是保证输入和输出的方差保持一致；like BN？
我们的做法是，根据进入神经元和输出神经元的权重数量和权重的初始化建立联系。因为如果进入神经元的权重越多，那么这个权重应该初始化的比较小；

简单来说，就是将一个神经元的初始值权重初始化为均值为0，方差为 Var(wi)=1nin 的随机分布（高斯或者均匀分布）。其中 nin 是该神经元的输入数目。

![参考](https://zjuturtle.com/2018/05/10/xavier-init/)

但是针对到relu函数，这里仍然会出问题：

原因是，每次运用relu函数的时候，由于relu函数的特性，他会使得一般的输出为0；自然输出的方差也改变了；所以我们使用之前的方法，使输出方差变为上文的两倍，即2/n.
