#information
#Time = 0:20:13
#Description: 정답은 맞지만, 느림

#Answer
def solution(players, callings):
#define
    answer = []

#Pretreatment


#Main
    for playerName in range(len(callings)):         
        for i in range(len(players)):
            if(players[i] == callings[playerName] and i>0):
                players.insert(i-1,callings[playerName])
                players.pop(i+1)
                break
                
    answer = players

    return answer

#Test Code
players = ["mumu", "soe", "poe", "kai", "mine"]
callings = ["kai", "soe", "kai", "mine", "mine"]
print(solution(players, callings))