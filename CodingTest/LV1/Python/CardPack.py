#information
#Time = 00:23:30
#Description: 조금 더 코드를 간결하게 짤 수 있도록 노력해야할 듯..
#Solving Method: https://www.notion.so/holoomstudio/ba57d5535d174c07addede9c92b12726

#Answer
def solution(cards1, cards2, goal):
    #define
    answer = ''
    finish = False
    #Pretreatment
    
    #Main
    while not(finish):
        if(len(goal) == 0): return "YES"
        
        if(len(cards1) != 0 and len(cards2) != 0):
            if(cards1[0] == goal[0] or cards2[0] == goal[0]):
                if(cards1[0] == goal[0]): 
                    cards1.pop(0)
                    goal.pop(0)
                if(cards2[0] == goal[0]): 
                    cards2.pop(0)
                    goal.pop(0)
            else: return "NO"

        elif(len(cards1) != 0):
             if(cards1[0] == goal[0]): 
                    cards1.pop(0)
                    goal.pop(0)
             else: return "NO"
        else: 
             if(cards2[0] == goal[0]): 
                    cards2.pop(0)
                    goal.pop(0)
             else: return "NO"

    return "YES"
   
   
#Test Code
cards1 = ["i", "drink", "water"]
cards2 = ["want", "to"]
goal = ["i", "want", "to", "drink", "water"]
print(solution(cards1, cards2, goal))