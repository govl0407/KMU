import pandas as pd
file = 'gts-seoul.csv'
df = pd.read_csv(file)#csv파일 열기

row = df[df['일시']=='2011-03-21 06:00']#해당 시간의 열 추출
print(row['습도']+row['풍속']+row['현지기압']+row['기온']+row['이슬점 온도'])

#전처리
s_column = ['습도','풍속','현지기압','기온','이슬점 온도']#해당 열 추출
s_data = df[s_column].dropna()#nan값을 가지는 행을 지움
d_len =len(s_data)#데이터의 크기
#d_len = s_data.shape[0]
print(d_len)
av_hum = df['습도'].mean()#평균
max_spe = df['풍속'].max()#최대값
min_temp = df['기온'].min()#최소값
print(av_hum+max_spe+min_temp+d_len)

#상관계수 corr = 상관계수
cor1 = s_data['습도'].corr(s_data['이슬점 온도'])
cor2 = s_data['풍속'].corr(s_data['이슬점 온도'])
cor3 = s_data['현지기압'].corr(s_data['이슬점 온도'])
cor4 = s_data['기온'].corr(s_data['이슬점 온도'])
print(cor1+cor2+cor3+cor4)

#산점도
import matplotlib.pyplot as plt
hum = s_data['습도']
win = s_data['풍속']
pascal = s_data['현지기압']
temp = s_data['기온']
E_temp = s_data['이슬점 온도']

plt.subplot(2,2,1)#2*2 에서 1번재 칸에 그려줌
plt1 = plt.scatter(hum, E_temp)#산점도 그리기
#plt.figure()#그래프를 하나씩 따로 출력해줌
plt.subplot(2,2,2)
plt2 = plt.scatter(win, E_temp)
#plt.figure()
plt.subplot(2,2,3)
plt3 = plt.scatter(temp, E_temp)
#plt.figure()
plt.subplot(2,2,4)
plt4 = plt.scatter(pascal, E_temp)
#plt.tight_layout()#그래프 사이의 여백 만들어줌
plt.show()

s_data= s_data[s_data['현지기압']>200]#현지기압이 200이상인 열만 추출
print(len(s_data))#행의 수
cor1 = s_data['습도'].corr(s_data['이슬점 온도'])
cor2 = s_data['풍속'].corr(s_data['이슬점 온도'])
cor3 = s_data['현지기압'].corr(s_data['이슬점 온도'])
cor4 = s_data['기온'].corr(s_data['이슬점 온도'])
print(cor1+cor2+cor3+cor4)

s_data= s_data[s_data['현지기압']>200]
hum = s_data['습도']
win = s_data['풍속']
pascal = s_data['현지기압']
temp = s_data['기온']
E_temp = s_data['이슬점 온도']
plt1 = plt.scatter(hum, E_temp)
plt.figure()
plt2 = plt.scatter(win, E_temp)
plt.figure()
plt3 = plt.scatter(temp, E_temp)
plt.figure()
plt4 = plt.scatter(pascal, E_temp)
plt.tight_layout()
plt.show()

#regression기법
from sklearn.linear_model import LinearRegression
x_train = s_data[['습도','풍속','현지기압','기온']]#학습 데이터x1,x2,x3,x4
y_train = s_data['이슬점 온도']#학습데이터 y
lr = LinearRegression()#모델 생성 y = a1*x1 + a2*x2 + --- +b
lr.fit(x_train,y_train)#학습

print(lr.coef_,'\n',lr.intercept_)#coef = a, intercept = b

#pre = (lr.coef_[0] * s_data['습도'] +  lr.coef_[1] * s_data['풍속'] +lr.coef_[2] * s_data['현지기압'] +
# lr.coef_[3] * s_data['기온'] + lr.intercept_)
pre = lr.predict(x_train)#학습한 값을 바탕으로 입력 x에 대해 y값을 만들어줌
mse = ((pre-s_data['이슬점 온도'])**2).mean() #평균제곱 오차=(실제값 - 계산값)^2의 평균
print(mse)

import pickle
import matplotlib.pyplot as plt
plt.figure(dpi = 200)#사진 크기 변경
data = pickle.load(open("mid_animal_data_pub.pkl","rb"))
for i in range(10):
    plt.subplot(5,2,i+1)
    plt.imshow(data['test1_images'][i])
    plt.axis('off')

plt.show()

#코사인 유사도
import numpy as np
a = data['train_vectors'][0]
b = data['test1_vectors'][1]
def cos(a,b):#코사인 유사도 계산
  dots = np.dot(a,b)
  cos1 = dots/(np.linalg.norm(a)*np.linalg.norm(b))
  return cos1
cos1 = cos(a,b)
print(cos1)

costs = []
for i in range(10):
  tmp =[]#train_vector 1개씩에 대한 코사인 유사도 저장
  for j in range(len(data['train_vectors'])):#test_vector의 원소 10개에 대해서
    a = cos(data['test1_vectors'][i],data['train_vectors'][j])#train_vector와 코사인 유사도 계산
    tmp.append([j,a])
  costs.append(tmp)
print(costs)
for i in range(10):
  costs[i].sort(key = lambda x:x[1])#코사인 유사도로 정렬
  costs[i].reverse()#내림차순
print(costs)
s=0
for i in range(10):
  for j in range(3):
    s+=costs[i][j][0]
print(s)

import matplotlib.pyplot as plt


for i in range(10):
    for j in range(3):
        ind = costs[i][j][0]
        image = data['train_images'][ind]

        plt.imshow(image)
        plt.axis('off')
        plt.figure()

plt.show()

#softmax regression
import torch
import torch.nn as nn
import torch.nn.functional as F
x_train = torch.from_numpy(data['train_vectors'])#학습데이터 x
y_train = torch.from_numpy(data['train_labels'])#학습데이터 y
model = nn.Linear(256,3)#모델 생성(x의 차원,y의 차원)
optim = torch.optim.Adam(model.parameters(),lr=0.01)#lr= learning rate

for epoch in range(10001):#학습
  z = model(x_train)
  cost = F.cross_entropy(z,y_train)
  optim.zero_grad()
  cost.backward()
  optim.step()

  with torch.no_grad():
    if epoch % 1000 == 0:
      print(f"epoch:{epoch},cost:{cost.item()}")

#sklearn softmax
import numpy as np
from sklearn.linear_model import LogisticRegression
logistic = LogisticRegression() # 모델 생성
logistic.fit(x_train, y_train) # 학습
pred = logistic.predict(data['test2_vectors'])
print(pred)