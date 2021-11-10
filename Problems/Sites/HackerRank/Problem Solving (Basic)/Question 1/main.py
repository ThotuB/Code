def getMinCost(crew_id, job_id):
    cost = 0
    crew_id.sort()
    job_id.sort()

    n = len(crew_id)
    for i in range(n):
        cost += abs(crew_id[i] - job_id[i])

    return cost


if __name__ == '__main__':
    crew_id = [5, 3, 1, 4, 6]
    job_id = [9, 8, 3, 15, 1]

    print(getMinCost(crew_id, job_id))