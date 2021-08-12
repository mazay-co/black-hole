import matplotlib.pyplot as plt
import numpy as np
import math
m = 3 # порядок кривой + 1
# рекурсивная функция расчета базисных функций
def N(tvect,m, i, t):
    if (m == 1):
        if (t >= tvect[i] and t <tvect[i+1]):
            return 1 
        else:
            return 0
    else:
        return (((t - tvect[i])/(tvect[i+m-1]-tvect[i]))*N(tvect,m-1,i,t)+
                (((tvect[i+m]-t)/(tvect[i+m]-tvect[i+1]))*N(tvect,m-1,i+1,t)))

def draw_nurbs(pointsN, m, color='blue'):
    # инициализация tvect
    tvect = [1 for i in range(len(pointsN)+m)]
    # вычисление вектора параметризации для NURBS
    for i in range(len(pointsN)-m):
        tvect[m+i] = (1 + i) / (1 + len(pointsN) - m)
    for i in range(m):
        tvect[i] = 0.0001 * i
        tvect[len(tvect)-1-i] = 1 - 0.0001 * i
    for i in range(len(tvect)):
        print(tvect[i]," ") # вывод массива вектора параметризации

    # вывод количества точек для построения NURBS
    print('Build dots, count = ', len(pointsN))

    # задание параметра t
    t = np.linspace(0, 1, 100)

    # задание весов wi
    wi = [1, (math.sqrt(2)/2), 1, (math.sqrt(2)/2), 1, (math.sqrt(2)/2), 1]
        
    # высчитываем координаты x в зависимости от параметра t и весов wi
    x_t=[]
    for j in range(len(t)):
        x_t.insert(j, 0)
        for i in range(len(pointsN)):
            x_t[j] += N(tvect,m, i, t[j]) * wi[i] * pointsN[i][0]
            
    # высчитываем координаты y в зависимости от параметра t и весов wi
    y_t=[]
    for j in range(len(t)):
        y_t.insert(j, 0)
        for i in range(len(pointsN)):    
            y_t[j] += N(tvect,m, i, t[j]) * wi[i] * pointsN[i][1]
                
    # построение графика
    plt.plot(x_t, y_t, color=color)
    return


def draw_beziercurve(p0, p1, p2, p3, color='red'):
    # задание параметра t (опорные точки)
    t = np.linspace(0, 1, 100)

    # высчитываем координаты x в зависимости от параметра t
    x_t = (1-t)**3*p0[0] + 3*t*(1-t)**2*p1[0] + 3*t**2*(1-t)*p2[0] + t**3*p3[0]
    
    # высчитываем координаты y в зависимости от параметра t
    y_t = (1-t)**3*p0[1] + 3*t*(1-t)**2*p1[1] + 3*t**2*(1-t)*p2[1] + t**3*p3[1]
    
    plt.plot(x_t, y_t, color=color)
    return


if (__name__ == '__main__'):
    # задание опорных точек
    p0 = [0, -6]
    p1 = [-6, -6]
    p2 = [-6, 0]
    
    p3 = [-6, 6]
    
    p4 = [0, 6]
    p5 = [6, 6]
    
    p6 = [6, 0]
    p66 = [6, -2]
    p67 = [8, -4]
    p7 = [8, -6]
    
    p8 = [8, -8] 
    p89 = [6, -10]
    p9 = [4, -10]
    p10 = [3, -10]
    p11 = [2, -6]

    # задание точек для гладкости кривой Безье
    p23 = [ (p2[0]+p3[0])/2 , (p2[1]+p3[1])/2 ]
    p34 = [ (p3[0]+p4[0])/2 , (p3[1]+p4[1])/2 ]
    p56 = [ (p5[0]+p6[0])/2 , (p5[1]+p6[1])/2 ]
    #==========================================================#

    # массив опорных точек для Безье
    points = [p0, p1, p2, p23, p3, p34, p4, p5, p56, p6, p66, p67,
              p7, p8, p89, p9, p10, p11, p0]
    # вывод количtcтва точек для построения кривой Безье
    print('Build dots, count = ', len(points))
    
    # массив опорных точек для NURBS
    pointsN = [p0, p1, p2, p3, p4, p5, p6]
            
    # нанесение опорных точек на график
    for p in points:
        plt.plot(p[0], p[1], marker='o', color='blue')

    # кривая Безье построение по 4-м точкам
    for i in range(6):
        draw_beziercurve(points[3*i], points[3*i + 1],
                        points[3*i + 2], points[3*i + 3], color='red')

    # график NURBS
    draw_nurbs(pointsN, m,'purple')

    # отрисовка сетки
    plt.grid(True)
    # задаём одинаковый масштаб осей
    plt.axis('equal')

    # вывод графиков
    plt.show()

