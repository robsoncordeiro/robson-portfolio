# Research Projects
This folder contains example projects developed when performing research work in collaboration with graduate students that I advised and/or other researchers. A brief description of each project is given in the following.

<h2>The Method D.MCA for Micro-Cluster Detection</h2>
            
<p>
    How can we detect outliers, both scattered and clustered, and also explicitly assign them to respective micro-clusters, without knowing apriori how many micro-clusters exist? How can we perform both tasks in-house, i.e., without any post-hoc processing, so that both detection and assignment can benefit simultaneously from each other? Presenting outliers in separate micro-clusters is informative to analysts in many real-world applications. However, a naïve solution based on post-hoc clustering of the outliers detected by any existing method suffers from two main drawbacks: (a) appropriate hyperparameter values are commonly unknown for clustering, and most algorithms struggle with clusters of varying shapes and densities; (b) detection and assignment cannot benefit from one another. Our algorithm D.MCA tackles the problem. It performs both detection and assignment iteratively, and in-house, by using a novel strategy that prunes entire micro-clusters out of the training set to improve the performance of the detection. It also benefits from a novel strategy that avoids clustered outliers to mask each other, which is a well-known problem in the literature. Also, D.MCA is designed to be robust to a critical hyperparameter by employing a hyperensemble "warm up" phase. Experiments performed on 16 real-world and synthetic datasets demonstrate that D.MCA outperforms 8 state-of-the-art competitors, especially on the explicit outlier micro-cluster assignment task.
</p>
<p>
<a href="https://doi.org/10.1109/ICDM54844.2022.00119"><b>Conference Publication</b></a><br/>
</p>
    
<h2>The Method BF-PSR for the Early Detection of Grooming</h2>
        
<p>
    Detecting grooming behavior in online conversations has become a growing problem due to the large number of messaging platforms that children and young people use nowadays. The biggest drawback is the lack of tools focused on the automatic prevention of this risk. Our method BF-PSR helps in tackling the problem. It incorporates seven behavioral features that we propose into a novel framework for the early detection of grooming. Experimental results reveal that our method outperforms all the concurrent methods and obtains state-of-the-art performance in the area of early grooming detection. Specifically, the new BF-PSR framework achieves a gain of more than 40% in effectiveness over five competitors when only 10% of the conversations' content is available, thus it shows a substantial advantage to allow the early detection of grooming; besides, it maintains a similar gain in effectiveness as more data arrives. To our knowledge, this is the first approach to employ behavioral features for the early detection of grooming. Furthermore, we have assembled two new datasets called PJZ and PJZC to mitigate the lack of data in the grooming detection area. Both sets are also publicly available for download aimed at fostering further researches.
</p>
<p>
    <a href="https://doi.org/10.1016/j.knosys.2021.108017"><b>Journal Publication</b></a><br/>
</p>

<h2>The Method C-AllOut for Catching and Calling Outliers by Type</h2>
        
<p>
    Given an unlabeled dataset, wherein we have access only to pairwise similarities (or distances), how can we effectively (1) detect outliers, and (2) annotate/tag the outliers by type? Outlier detection has a large literature, yet we find a key gap in the field: to our knowledge, no existing work addresses the outlier annotation problem. Outliers are broadly classified into 3 types, representing distinct patterns that could be valuable to analysts: (a) global outliers are severe yet isolate cases that do not repeat, e.g., a data collection error; (b) local outliers diverge from their peers within a context, e.g., a particularly short basketball player; and (c) collective outliers are isolated micro-clusters that may indicate coalition or repetitions, e.g., frauds that exploit the same loophole. Our method C-AllOut is a novel and effective outlier detector that annotates outliers by type. It is parameter-free and scalable, besides working only with pairwise similarities (or distances) when it is needed. Experiments show that C-AllOut achieves on par or significantly better performance than state-of-the-art detectors when spotting outliers regardless of their type. It is also highly effective in annotating outliers of particular types, a task that none of the baselines can perform.
</p>

<p>
    <a href="https://arxiv.org/abs/2110.08257"><b>arXiv Paper</b></a><br/>
</p>

<h2>The Method FReE for Dimensionality Reduction in Big Data</h2>
        
<p>
    Given a set of millions or even billions of complex objects for descriptive data mining, how to effectively reduce the data dimensionality? It must be performed in an unsupervised way. Unsupervised dimensionality reduction is essential for analytical tasks like clustering and outlier detection because it helps to overcome the drawbacks of the “curse of high dimensionality”. The standard approach is to preserve the data variance by means of well-known techniques, such as PCA, KPCA, SVD, and other techniques based on those that have been mentioned, such as PUFS. Our method FReE follows a distinct approach. It is a Fractal-based algorithm that accurately and efficiently removes redundant attributes in Big Data. Experiments show that it consistently outperforms the standard variance-preservation strategy.
</p>

<p>
    <a href="https://doi.org/10.1016/j.knosys.2020.105777"><b>Journal Publication</b></a><br/>
</p>

<h2>The Method HySortOD for Fast and Scalable Outlier Detection</h2>
        
<p>
Outlier detection is the task responsible for finding novel or rare phenomena that provide valuable insights in many areas of the industry. The neighborhood-based algorithms are largely used to tackle this problem due to the intuitive interpretation and wide applicability in different domains. Their major drawback is the intensive neighborhood search that takes hours or even days to complete in large data, thus being impractical in many real-world scenarios. Our method HySortOD is a novel algorithm that uses an efficient hypercube-ordering-and-searching strategy for fast outlier detection. Its main focus is the analysis of data with many instances and a low-to-moderate number of dimensions. We performed comprehensive experiments using real data with up to ~500k instances and ~120 dimensions, where our new algorithm outperformed 7 state-of-the-art competitors in runtime, being up to 4 orders of magnitude faster in large data. One case study in the crucial task of breast cancer detection was also performed to demonstrate that our approach can be successfully used as an out-of-the-box solution for real-world, non-benchmark problems.
</p>

<p>
    <a href="https://doi.org/10.1145/3340531.3412033"><b>Conference Publication</b></a><br/>
</p>

<h2>Detection of Game Influencers</h2>
        
<p>
Online games have become a popular form of entertainment, reaching millions of players. Among these players are the game influencers, that is, players with high influence in creating new trends by publishing online content, such as videos, blogs and forums. Other players follow the influencers to appreciate their game contents. Game companies invest in influencers to promote their products. However, how to identify the game influencers among millions of players of an online game? Our method tackles the problem by extracting temporal aspects of the players' actions, and then detecting the game influencers by performing a classification analysis. Experiments with the well-known Super Mario Maker game, from Nintendo Inc., Kyoto, Japan, show that our approach detects game influencers of different nations with high accuracy.
</p>

<p>
    <a href="https://doi.org/10.5220/0007728200930103"><b>Conference Publication</b></a><br/>
</p>

<h2>The Method ULEARn for Retrieval and Analysis of Skin Ulcer Images</h2>
        
<p>
Bedridden patients with skin lesions (ulcers) often do not have access to specialized clinic equipment. It is important to allow healthcare practitioners to use their smartphones to leverage information regarding the proper treatment to be carried out. Existing applications require special equipment, such as heat sensors, or focus only on general information. Our method ULEARn helps in tackling this problem. It is a DBMS-based framework for the processing of ulcer images, providing tools to store and retrieve similar images of past cases. The proposed mobile application ULEARn-App allows healthcare practitioners to send a photo from a patient to ULEARn, and obtain a timely feedback that allows the improvement of procedures on therapeutic interventions. Experimental results of ULEARn and ULEARn-App using a real-world dataset showed that our tool can quickly respond to the required analysis and retrieval tasks, being up to 4.6 times faster than the specialist's expected execution time.
</p>

<p>
    <a href="https://doi.org/10.5753/sbbd.2019.8812"><b>Conference Publication</b></a><br/>
</p>

<h2>The Method ORFEL for Detecting Defamation and Illegitimate Promotion</h2>
        
<p>
What if a successful company starts to receive a torrent of low-valued (one or two stars) recommendations in its mobile apps from multiple users within a short (say one month) period of time? Is it legitimate evidence that the apps have lost in quality, or an intentional plan (via lockstep behavior) to steal market share through defamation? In the case of a systematic attack to one's reputation, it might not be possible to manually discern between legitimate and fraudulent interaction within the huge universe of possibilities of user-product recommendation. Previous works have focused on this issue, but none of them took into account the context, modeling, and scale that we consider. Our method ORFEL is a novel approach to detect defamation and/or illegitimate promotion of online products by using vertex-centric asynchronous parallel processing of bipartite (users-products) graphs. With an innovative algorithm, our results demonstrate both efficacy and efficiency – over 95% of potential attacks were detected, and ORFEL was at least two orders of magnitude faster than the state-of-the-art. It deals with relevant issues of the Web 2.0, potentially augmenting the credibility of online recommendation to prevent losses to both customers and vendors.
</p>

<p>
    <a href="https://doi.org/10.1016/j.ins.2016.09.006"><b>Journal Publication</b></a><br/>
</p>

<h2>The Method Curl-Remover for Dimensionality Reduction in Big Data</h2>
        
<p>
Given a very large dataset of moderate-to-high dimensionality, how to mine useful patterns from it? In such cases, dimensionality reduction is essential to overcome the “curse of dimensionality”. Although there exist algorithms to reduce the dimensionality of Big Data, unfortunately, they all fail to identify/eliminate non-linear correlations between attributes. Our method Curl-Remover helps in tackling the problem by exploring concepts of the Fractal Theory and massive parallel processing. It is a novel dimensionality reduction technique for very large datasets. Our contributions are: Curl-Remover eliminates linear and non-linear attribute correlations as well as irrelevant attributes; it is unsupervised and suits for analytical tasks in general – not only classification; it presents linear scale-up; it does not require the user to guess the number of attributes to be removed, and; it preserves the attributes' semantics. Experiments on synthetic and real data spanning up to 1.1 billion points show that Curl-Remover is up to 8% more accurate than a PCA-based algorithm.
</p>

<p>
    <a href="https://doi.org/10.1109/ICDMW.2016.0093"><b>Workshop Publication</b></a><br/>
</p>

<h2>The Method M-Flash for Fast Billion-Scale Graph Computation</h2>
        
<p>
Recent graph computation approaches have demonstrated that a single PC can perform efficiently on billion-scale graphs. While these approaches achieve scalability by optimizing I/O operations, they do not fully exploit the capabilities of modern hard drives and processors. To overcome their performance, our method M-Flash leverages the Bimodal Block Processing to be the fastest graph computation framework to date. It is also a flexible and simple programming model to easily implement popular and essential graph algorithms, including the first single-machine billion-scale eigensolver. Extensive experiments on real graphs with up to 6.6 billion edges demonstrate M-Flash's consistent and significant speedup.
</p>

<p>
    <a href="https://doi.org/10.1007/978-3-319-46227-1_39"><b>Conference Publication</b></a><br/>
</p>

<h2>The Method Halite for Correlation Clustering</h2>

<p>
    The algorithm Halite is a fast and scalable density-based clustering algorithm for moderate-to-high-dimensionality data able to analyze large collections of complex data elements. It creates a multi-dimensional grid all over the data space and counts the number of points lying at each hyper-cubic cell provided by the grid. A hyper-quad-tree-like structure, called the Counting-tree, is used to store the counts. The tree is thereafter submitted to a filtering process able to identify regions that are, in a statistical sense, denser than its neighboring regions regarding at least one dimension, which leads to the final clustering result. The algorithm is fast and it has linear or quasi-linear time and space complexity regarding both the data size and the dimensionality.
</p>
<p>
    <b>Remark:</b> A first implementation of Halite was initially named as the method MrCC (after Multi-resolution Correlation Clustering) in an earlier <a href="http://doi.ieeecomputersociety.org/10.1109/ICDE.2010.5447924"><b>Conference Publication</b></a> of this work. Later, it was renamed to Halite for clarity, since several improvements on the initial implementation were included into a <a href="http://doi.ieeecomputersociety.org/10.1109/TKDE.2011.176"><b>Journal Publication</b></a>.
</p>
<p>
    <a href="http://doi.ieeecomputersociety.org/10.1109/ICDE.2010.5447924"><b>Conference Publication</b></a><br/>
    <a href="http://doi.ieeecomputersociety.org/10.1109/TKDE.2011.176"><b>Journal Publication</b></a>
</p>
    
    
<h2>The Method BoW for Clustering Terabyte-scale Datasets</h2>
    
<p>
    The method BoW focuses on the problem of finding clusters in Terabytes of moderate-to-high dimensionality data, such as features extracted from billions of complex data elements. In these cases, a serial processing strategy is usually impractical. Just to read a single Terabyte of data (at 5GB/min on a single modern eSATA disk) one takes more than 3 hours. BoW explores parallelism and can treat as plug-in almost any of the serial clustering methods. The major research challenges addressed are (a) how to minimize the I/O cost, taking care of the already existing data partition (e.g., on disks), and (b) how to minimize the network cost among processing nodes. Either of them may become the bottleneck. Our method automatically spots the bottleneck and chooses a good strategy, one of them uses a novel sampling-and-ignore idea to reduce the network traffic. Specifically, BoW combines (a) potentially any serial algorithm used as a plug-in and (b) makes the plug-in run efficiently in parallel, by adaptively balancing the cost for disk accesses and network accesses, which allows BoW to achieve a very good tradeoff between these two possible bottlenecks.
</p>
<p>
    <a href="http://doi.acm.org/10.1145/2020408.2020516"><b>Conference Publication</b></a><br/>
</p>
    
<h2>The Method QuMinS for Labeling and Summarization</h2>
    
<p>
    The algorithm QuMinS focuses on two distinct data mining tasks - the tasks of labeling and summarizing large sets of moderate-to-high dimensionality data, such as features extracted from Gigabytes of complex data elements. Specifically, QuMinS is a fast and scalable solution to two problems (a) low-labor labeling - given a large collection of data objects, very few of which are labeled with keywords, find the most suitable labels for the remaining ones, and (b) mining and attention routing - in the same setting, find clusters, the top-NO outlier objects, and the top-NR representative objects. The algorithm is fast and it scales linearly with the data size, besides working even with tiny initial label sets.
</p>
<p>
    <b>Remark:</b> A first implementation of QuMinS was initially named as the method QMAS (after Querying, Mining And Summarizing Multi-modal Databases) in an earlier <a href="http://doi.ieeecomputersociety.org/10.1109/ICDM.2010.150"><b>Conference Publication</b></a> of this work. Later, it was renamed to QuMinS for clarity, since several improvements on the initial implementation were included into a <a href="http://dx.doi.org/10.1016/j.ins.2013.11.013"><b>Journal Publication</b></a>.
</p>
<p>
    <a href="http://doi.ieeecomputersociety.org/10.1109/ICDM.2010.150"><b>Conference Publication</b></a><br/>
    <a href="http://dx.doi.org/10.1016/j.ins.2013.11.013"><b>Journal Publication</b></a><br/>
</p>
