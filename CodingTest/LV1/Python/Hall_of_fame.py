#information
#Time = 
#Description: 

#Answer
def solution(k, score):
    #define
    answer = []
    Ranking = []


    #Main
    notice = sorted(score,reverse=True)

    if(len(Ranking) < k):
        for i in notice:
            Ranking.append(i)
            answer.append(Ranking[0])
    if(len(Ranking) >= k):
        for i in notice:
            



    return notice[k-1]

#Test Code
k = 3
score = [10, 100, 20, 150, 1, 100, 200]
result = [10, 10, 10, 20, 20, 100, 100]

print(solution(k,score))