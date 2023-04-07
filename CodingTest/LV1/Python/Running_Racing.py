#information
#Time = 1:20:13
#Description: 1번째 시도한 부분에서, Callings가 반복적으로 불리는 부분에 대하여, 전처리를 하고 진행하는 방식으로 했지만, 여전히 느림


#Answer
def solution(players, callings):
#define
    answer = []
    callingName = ''
    callingTimes = 1

#Pretreatment


#Main
    while len(callings) > 0:
        for times in range(len(callings)):
            callingName = callings[times]
            if(times < len(callings)-1):
                if(callings[times] == callings[times+1]):
                    callingTimes += 1
                    print(callings[times])
                elif(times+1 == len(callings)): 
                    callingTimes += 1
                    print(callings[times])
                    break
                else: break
        del callings[0:callingTimes]

        for i in range(len(players)):
            if(players[i] == callingName):
                players.insert(i-callingTimes,callingName)
                print(i,":",callingTimes)
                print(i,":",players)
                if(callingTimes == 1):
                    players.pop(i+callingTimes)
                else: players.pop(i+callingTimes-1)
                callingTimes = 1
                print(i,":",players)
                print(i,":",len(callings))
                break
                
    answer = players

    return answer

#Test Code
players = ["mumu", "soe", "poe", "kai", "mine"]
callings = ["kai", "soe", "kai", "mine", "mine"]
print(solution(players, callings))