## Notes

## Week 1

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

对于**alphago**来说，下采样或者其他方式采用没有任何物理意义。因为池化的本身目的就是要保留图像的部分特征，对于alphago这种选择的模型来说，池化没有任何意义。所以alphago中没有池化的概念。alpha go 的feature map中不具备任何的location invariance behavior,所以只有卷积层，而没有pooling层。

## Week 2

1/15

<<<<<<< HEAD:EECE7398_DL/Notes.md
### Activation Layer:
=======
- Activation Layer:
>>>>>>> c311561312b5aca562b0d4cac47afe4feb345592:EECE5698_DL/Notes.md

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

<<<<<<< HEAD:EECE7398_DL/Notes.md
### supervised and unsupervised learning
=======
- supervised and unsupervised learning
>>>>>>> c311561312b5aca562b0d4cac47afe4feb345592:EECE5698_DL/Notes.md

no essenital gap! 唯一的区别就是label，他们所做的事情是一样的。

classification 和 regression

其实在本质上是相同的，我们都会得出一个分数，classification会输出最大分数对应的类。而regression直接会输出最大的分数。



<<<<<<< HEAD:EECE7398_DL/Notes.md
### minimum question
=======
- minimum question
>>>>>>> c311561312b5aca562b0d4cac47afe4feb345592:EECE5698_DL/Notes.md

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

这是因为，如果只有一个样本去测试，那么它都均值将会是它本身。这是alpha项将为0，这时输出的结果将会只有beta。所有的输出结果都会保持不变。
这时我们通过一个bool变量，来调控bn层。

![BN](https://raw.githubusercontent.com/liuyaqiao/Learning-Note/master/BN.png)

BN层是在激活层之前加入，对于mini-batch的SGD，我们的变换公式就可以写成：

<a href="https://www.codecogs.com/eqnedit.php?latex=x^{(k)}&space;=&space;\frac{x^{(k)}&space;-&space;E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x^{(k)}&space;=&space;\frac{x^{(k)}&space;-&space;E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" title="x^{(k)} = \frac{x^{(k)} - E[x^{(k)}]}{\sqrt{Var[x^{(k)}]}}" /></a>

如果只进行这样的变换会带来网络表达能力的下降，所以我们加入两个参数，这两个参数是通过学习得到：（因为它意味只利用了激活函数的线性部分，可能造成表达能力的下降。）

<a href="https://www.codecogs.com/eqnedit.php?latex=y^{(k)}&space;=&space;\gamma&space;^{(k)}x^{(k)}&space;&plus;&space;\beta^{(k)}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?y^{(k)}&space;=&space;\gamma&space;^{(k)}x^{(k)}&space;&plus;&space;\beta^{(k)}" title="y^{(k)} = \gamma ^{(k)}x^{(k)} + \beta^{(k)}" /></a>

所以BN为了保证非线性的获得，对变换后的满足均值为0方差为1的x又进行了scale加上shift操作(y=scale*x+shift)，每个神经元增加了两个参数scale和shift参数，这两个参数是通过训练学习到的，意思是通过scale和shift把这个值从标准正态分布左移或者右移一点并长胖一点或者变瘦一点，每个实例挪动的程度不一样，这样等价于非线性函数的值从正中心周围的线性区往非线性区动了动。核心思想应该是想找到一个线性和非线性的较好平衡点，既能享受非线性的较强表达能力的好处，又避免太靠非线性区两头使得网络收敛速度太慢。

一般是加在激活层之前，但是当act函数是relu的时候，加在relu后面效果更好。

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

<<<<<<< HEAD:EECE7398_DL/Notes.md
## week 4

1/29

tensorflow tutorial

- tensorflow 是通过graph定义的方式来进行计算的；
- 一般用variable来储存变量，一般是要进行训练的量，例如weights or bias.
- 一般用placeholder来储存输入，它一般

在定义完graph之后，要记得去run，否则它仍然以graph的形式存在。
所有的参数在session之前要做一次init
=======

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

它的目的是：尽可能的让输入和输出服从相同的分布，这样就能够避免后面层的激活函数的输出值趋向于0，这样使每一层的分布都接近于均值是0方差相同。所以，我们想办法使得他们的方差保持一致，这里是保证输入和输出的方差保持一致；

我们的做法是，根据进入神经元和输出神经元的权重数量和权重的初始化建立联系。因为如果进入神经元的权重越多，那么这个权重应该初始化的比较小；

简单来说，就是将一个神经元的初始值权重初始化为均值为0，方差为 Var(wi)=1nin 的随机分布（高斯或者均匀分布）。其中 nin 是该神经元的输入数目。

该分析的直观性解释可以分为两部分，首先对于前向传播，我们需要确保所有层的激活值方差近似相等，因此每一个训练样本传播经过网络的信息才能保持平滑的属性。同样对于反向传播，每层梯度保持近似的方差将允许信息平滑地反向流动以更新权重。近似方差的梯度同样确保误差数据能反馈到所有层级，因此它是整个训练过程中的关键。

**这里的思路可以理解为和BN相同，都是保持固定的方差和均值；使得激活函数对这些值有比较好的性质；不同的是，xavier是从权值初始化的角度来考虑这个问题，而BN是在每一次传递的时候，针对样本去优化这个问题；两者的结论是一样的，只是出发点和作用的时间不同；**

如果方差太大，会造成传播的时候产生的梯度太大；而方差太小，则个体差异较小，会造成传播的梯度较小；

[参考](https://zjuturtle.com/2018/05/10/xavier-init/)

[数学](https://cloud.tencent.com/developer/article/1119839)

但是针对到relu函数，这里仍然会出问题：

原因是，每次运用relu函数的时候，由于relu函数的特性，他会使得一般的输出为0；自然输出的方差也改变了；所以我们使用之前的方法，使输出方差变为上文的两倍，即2/n.

- update method

1. naive update
2. momentum update

在梯度的更新时同时考虑上一时刻的梯度对当前的影响。类似于物理之中动量的含义；

3. AdaGrad Update

学习率不能时固定的，在dw小的时候，增大学习率，dw大的时候减小学习率；

操作是把dw加入分子项；

4. RMSProp Update

将当前的变化表示成一个指数和的形式；是所有的平方项dw积累结果；


2/8

- 方差
方差大小和正向传播反向传播的关系：

如果在激活层之前的方差太大，我们可以认为有很多的值在-1 和 1周围，在激活函数之后就会发生激活的值很小，导致正向传播缓慢甚至停止。

而如果方差太小，则导致很多权值在0周围，这样导致反向传播回来的时候，权重更新比较缓慢。因为反向传播的时候，权重更新根据链式法则，和当前的w有关。

- 训练和预测中技术的一些区别：

我们在训练中需要做BN，但是在预测中不需要。因为，在预测中没有batch的存在。

同时，softmax误差可以在训练中使用，在预测中我们可以直接用分数来表示，这是一个道理。

dropout也是在训练中使用，而在预测中不需要使用；原因有：dropout会给预测带来随机性，每一个预测的结果。

在代码中，我们会使用一个placeholder把keep_prob 传入来控制是否做dropout。经过正向传播之后，被失活的神经元的权重是0，所以反向传播的时候，他们也不会起作用。

完成后要进行缩放：a/=keep_prob, keep_prob为保留一个节点的概率，通过缩放，在计算成本时任具有相同的期望值。

week 7

2/15

- Pooling

**为什么用pooling**
	1. 我们原来的feature map太大了，需要减少参数降低过拟合的风险。
	2.  因为我们的图片具有不变性，经过平移、旋转等操作之后，最大值依旧会是当前的最大值。这样经过池化之后依旧保持了原有的显著特征。

**为什么max pooling效果更好**

max pooling总能反应出最为显著的信息，一般是物体的纹理信息；而average pooling则只能反应出图片的背景信息；

**为什么可以用同样的filter 去对整个图像进行作用**

因为图像中的物体具有平移、旋转不变形；

- 常见的DNN

**GoogleLenet**

与其他的DNN不同，选用更深的网络去提取更多的特征，Googlenet是针对神经网络的另一个方面进行优化（宽度），它选择采用更多的尺寸的卷积核，能否一次提取更多的信息。所以它在一层上使用了三个维度的卷积核进行操作，通过多个卷积核组成了一个inception module，最后用一个合并的函数得出最终的feature map。但是，这带来的问题就是，大维度的卷积核会大幅度的提升参数的个数，带来计算量的增加和过拟合的风险。所以，它巧妙地运用了1维的卷积核去减少参数数量。

下面是inception module的示意图：

![inception](https://raw.githubusercontent.com/liuyaqiao/Learning-Note/master/inception.png)

至于为什么1维卷积核可以降低参数个数，这里是参考文件：
![computation](https://github.com/liuyaqiao/Learning-Note/blob/master/%E6%B7%B1%E5%BA%A6%E5%AD%A6%E4%B9%A0_%E5%88%98%E4%BA%9A%E6%A8%B5.pdf)

**ResNet**

ResNet出现的原因是：太深的网络会很严重出现梯度消失和梯度下降的问题，无法通过有效的手段进行训练。

![resmodule](https://raw.githubusercontent.com/liuyaqiao/Learning-Note/master/residual.png)

它把当前的输出和两层之前的输入一同加入到了activation函数去学习。这个新加入的梯度不会使得传入的梯度太小无法学习，可以有效的解决梯度弥散的问题。

2/22 

- DenseNet

Densenet 是resnet的扩展，它通过多层跳跃连接的方式来连接解决梯度消失。

缺点是参数比较多，不好训练。训练的时候需要很多的合并操作，需要的显存比较高。

- 1 维卷积核可以减少参数和计算的个数，有两个好处：
		1. 可以降低过拟合的风险
		2. 使得计算更快
		
- RNN

1. sequence to sequence: 
seq2seq 模型就像一个翻译模型，输入是一个序列（比如一个英文句子），输出也是一个序列（比如该英文句子所对应的法文翻译）。这种结构最重要的地方在于输入序列和输出序列的长度是可变的。

2. RNN的结构从两方面来解决这个问题：
	1.	hidden layer可以储存past information
	2. non-linear会带来不同的更新方式

3. RNN可以用在许多不同的方面；图片添加文字描述，翻译，video frame（one to many, many to one, many to many）

4. Feedforward: 每一层都利用相同的weight，下面是基本的结构：

用文字解释就是：
当前的状态是有当前的输入和前一轮的状态求和所决定，然后再通过一个非线性的函数构成；每一次的权重都是共享的；求出当前的状态量之后，再通过一个非线性的函数去进行处理；


双向RNN

5. BackPropagation --> BPTT

6. Gradient explosion and vanishing -- limit the numbers of steps -- long term dependency

7. Gate - forget long-term dependency
	1. LSTM
	通过引入cell state、input gate、forget gate和outputgate的方式实现长期记忆；
	cell state: 表示前些时刻的信息; 相当于小本子，用来记忆的东西；每次多储存了一些参数和状态，来完成long term memory。
	forget gate: 决定丢弃cell中的哪一部分
	input gate: 决定什么样的新信息课一加入到cell中
	output gate: 更新细胞状态后的h层输出
	
	为什么可以控制梯度消失：
	
	
	2. GRU


- Autoencoder

autoencoder 之前主要用于数据的降维和特征的提取，现在也会用在生成模型中。

- 主要由input layer, hidden layer 和 output layer组成。通常，我们用一个input denoise之后的图片用作输出。最优化的误差是：L(x, g(f(x)));

- 当decoder是线性的时候，并且L是MSE的时候，按 autoencoder 就变成了PCA。

这里就要比较一下PCA和AE。

PCA是常用的一种降维的方法，常用的降维分为线性和非线性的方法：

PCA和LDA都是线性的方法，他们按照某种准则为数据集找到一个最佳投影方向和截距，然后做线性变化得到一个降维的数据集。

而非线性方法中的典型就是AE。它是一种神经网络，通过加入非线性激活函数带来非线性。

由于AE可以实现非线性和深层结构，所以比PCA有很大的优势，是现在一个比较好的压缩和表示法学习。

预训练：

DNN会发生overfit，所以我们用预训练好的模型，在应用于当前数据集进行微调，一般来说效果会更好。而且容易陷入local minimum。

可以通过autoencoder来完成预训练，用在训练开始阶段，确定权重矩阵的初始值。这里为了控制参数的数量可以加入一些限制条件（Regurlariztion），L0比较好。

有监督预训练：在一个数据集上先训练好的一个一个模型，然后根据tuning fine去在新的新数据集上实现模型。
greedy layer-wise pre-training
无监督预训练：AE，把输入当作输出，然后进行训练，得到初始的权重。

现在有监督预训练的模型效果会更好。


需要注意的是：

1. AE没有pooling层，所以它不具备location不变性；
2. 如果把AE的压缩层用softmax去分类，就成了有监督学习，所以他们之间没有显著的区别；同压缩层去分类的话，可以加速分类；如果这个表示效果好的话，会有不错的分类效果；
3. 这和卷积、去卷积所做的事情类似；
4. kernel PCA一样可以带来非线性，但是相比于AE，它对参数更加敏感。

- best represetation
使用unsuprvisd pretraining一定程度上会提升收敛的速度，所以它可以一定程度上取代BN。

在现在的很多神经网络中，我们会使用average pooling代替全连接层。

首先我们关注一下全连接层的优缺点：
    优点：有时候效果不错
    缺点：参数量比较大比较多，造成了训练速度比较慢容易过拟合。

这里我们提出了用global average pooling代替；

全连接层所做的是把卷积层合成一个向量并且把输出的结果做一个整合；pooling层同样可以做到，我们可以看成GAP是在网络的结构上做正则化防止过拟合。缺点是使用gap可能使网络收敛变慢。



- Tranfer learning：
把已学训练好的模型参数迁移到新的模型来帮助新模型训练
why:
1.需要用DNN去提取特征
2.没有足量的数据
3.数据没有label
4.计算的资源比较少

缺点在于这种模型没有很好的理论支撑；

1. 起因：
现实中，往往不满足采样training和inference时，采用的数据服从相同的分布（distribution）、来源于相同的特征空间（feature space）。因为标记样本数有限，数据分布会发生变化。




>>>>>>> c311561312b5aca562b0d4cac47afe4feb345592:EECE5698_DL/Notes.md
