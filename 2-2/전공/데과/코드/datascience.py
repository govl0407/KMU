from sklearn.linear_model import LinearRegression
x = [[1,2], [3,2], [3,7], [1,1], [1,0]]
y = [[4], [8], [23], [1], [-2]]
lr = LinearRegression() # 모델 생성
lr.fit(x, y) # 학습 (피팅)

print(lr.coef_, lr.intercept_)