%%author:xinxliu<mailto:xinxinliux@gmail.com>

%%initilize the dataset
close all;
alpha1 = 0.3;
alpha2 = 0.5;
alpha3 = 0.2;
mu1 = [1,2];
mu2 = [7,3];
mu3 = [3,9];
sigma1 = [1,0.5;0.5,2];
sigma2 = [-2.5 4;4 -2];
sigma3 = [3 2;2 4];

p1 = repmat(mu1,1000*alpha1,1) + randn(1000*alpha1,2)*sigma1;
scatter(p1(:,1),p1(:,2));
hold on
p2 = repmat(mu2,1000*alpha2,1) + randn(1000*alpha2,2)*sigma2;
scatter(p2(:,1),p2(:,2));
hold on
p3 = repmat(mu3,1000*alpha3,1) + randn(1000*alpha3,2)*sigma3;
scatter(p3(:,1),p3(:,2));

%%initilize the paramaters






