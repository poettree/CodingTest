#information
#Time = 1:05:01
#Description: 완벽한 정답은 아님(1칸씩 이동하는것으로 계산, 정확한 조건은 방해물 등을 미리 계산 후 문제가 있으면 명령 취소)

#Answer
def mysplit(s):
    head = s.rstrip('0123456789')
    tail = s[len(head):]
    return head, tail

def AddToAnswer(s):
    if(s == "E"):
        return [0,1]
    elif(s == "S"):
        return [1,0]
    elif(s == "W"):
        return [0,-1]
    elif(s == "N"):
        return [-1,0]


def solution(park, routes):
    #define
    answer = []
    map = []
    new_routes = []
    obstacle = []
    
    #Pretreatment
    for i in range (len(park)):
        map.append(list(park[i]))
    
    for i in range (len(routes)):
        new_routes.append(mysplit(routes[i].replace(' ','')))

    for i in range (len(map)):
        for j in range (len(map[i])):
            if(map[i][j] == "S"):
                answer.append(i)
                answer.append(j)
            elif(map[i][j] == "X"):
                obstacle.append([i,j])
    print(answer)
    print(obstacle)

    #Main
    for i in range (len(new_routes)):
        for times in range (int(new_routes[i][1])):
            answer[0] += AddToAnswer(new_routes[i][0])[0]
            answer[1] += AddToAnswer(new_routes[i][0])[1]

            for x in range (len(obstacle)):
                if(answer == obstacle[x]):
                    answer[0] -= AddToAnswer(new_routes[i][0])[0]
                    answer[1] -= AddToAnswer(new_routes[i][0])[1]
            
    print("Answer:",answer)
            

    print(new_routes)
    print(map)
    
    return answer

#Test Code
park = ["SOO","OOO","OOO"]
routes = ["E 2","S 2","W 1"]
solution(park,routes)