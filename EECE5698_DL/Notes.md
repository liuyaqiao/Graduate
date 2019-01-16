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

