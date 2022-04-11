import numpy as np

def test_1(arr):
    red = arr[arr[:, :, 0] >= 100]
    yellow = red[red[:,  1] >= 100]

    print(red)
    print(yellow)
    
def test_2(arr):
    yellow = arr[(arr[:, :, 0] >= 100) & (arr[:, :, 1] >= 100)]

    print(yellow)


if __name__ == '__main__':
    arr = np.array([
        [
            [100, 50, 0],
            [0, 200, 250],
            [20, 100, 150],
            [200, 250, 0]],
        [
            [100, 150, 0],
            [300, 50, 250],
            [50, 0, 150],
            [200, 250, 0]],
    ])

    test_1(arr)
    test_2(arr)