import tensorflow as tf
import numpy as np
mnist = tf.keras.datasets.mnist

# Import data (Samples, 28, 28, 1)
(xTrain, yTrain), (xTest, yTest) = mnist.load_data()
xTrain = np.reshape(xTrain, (xTrain.shape[0], -1))
xTest = np.reshape(xTest, (xTest.shape[0], -1))
## the first argument is the array reshape
print(xTrain.shape)
print(yTrain.shape)
## the decrease the dimension
yTrain = np.squeeze(yTrain)
yTest = np.squeeze(yTest)
# Create the model
# 从外部传入的数据用placeholder接受，一般是输入
x = tf.placeholder(tf.float32, [None, 784])
y_ = tf.placeholder(tf.int64, [None])
# Variables
# 一般是weights和b
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))
# Output
y = tf.matmul(x, W) + b
# Define loss and optimizer
# reduce_mean axis 如果不指定就是所有元素的平均值，0是列，1是行
# 这是要转换成one_hot输出，后面的10是维度，这是一个计算出的值，y是模型的output。
cross_entropy = tf.reduce_mean(tf.losses.softmax_cross_entropy(tf.one_hot(y_, 10), logits=y))
train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)
sess = tf.InteractiveSession()

## interarctiveSession()
# 可以允许交互，而session（）则必须在构建好图之后再运行。

tf.global_variables_initializer().run()
# Train
# train 1000次
for _ in range(1000):
    s = np.arange(xTrain.shape[0])
    ## return 一个darray 是[0,...,60000]
    np.random.shuffle(s)
    # 将他们随机打算顺序
    # 并按照s的顺序排列
    xTr = xTrain[s]
    yTr = yTrain[s]
    # batch_size = 100
    batch_xs = xTr[:100]
    batch_ys = yTr[:100]
    loss, _ = sess.run([cross_entropy, train_step], feed_dict={x: batch_xs, y_: batch_ys})
print(loss)
# Test trained model
correct_prediction = tf.equal(tf.argmax(y, 1), y_)
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
print(sess.run(accuracy, feed_dict={x: xTest, y_: yTest}))

