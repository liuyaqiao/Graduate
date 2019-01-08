## Notes

Week 1

- motivation

    首先提出的是DNN，当DNN的层数增加后，一开始验证效果会提升，但随着深度继续增加，会出现performance的下降。这时候是因为有着更多的参数，出现了过拟合的现象。所以我们为了解决这个问题出现了CNN，它具有参数权值共享等优势。可以使网络层数更深，学到更多的特征。但是在网络不断加深的时候，出现了梯度弥散和梯度消失的问题（因为它们太小了，用求导的方法做的时候会消失）。这是提出了Resnet去解决这个梯度弥散的问题，但是在同样层数的Resnet和之前的传统DNN、CNN网络相比，Resnet不具有优越性，甚至是更低的准确度。所以，只有更深的网络才可以带来performance大幅度的提升，所以出现了Resnet101、Resnet152等。
    
- Criticism on Deep Learning

    1.  之前缺少对NN的数学研究，我们认为存在过多的local minimum，不容易找到真的的全局最优解。
    2.  NN的理论难以用我们现存的理论去解释。
    3.  不需要任何的domain knowledge，只是单纯的去收集数据、训练和验证。
    4. 过于依赖GPU等设备。

PCA是autoencoder的一种特殊形式。