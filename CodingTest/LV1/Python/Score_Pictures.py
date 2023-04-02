#information
#Time = 1:51:11
#Description: 딕셔너리를 이용하여 해결을 시도 했는데, Key와 Value에 대한 부분을 명확하게 이해하지 못하고 진행하다 보니, 시간지연이 되었다.

#Answer
def solution(name, yearning, photo):
    #define
    answer = []
    dictionary = {}
    unwanted = []
    temp = 0

    #Pretreatment
    for i in range(len(photo)):
        for values in photo[i]:
            if values not in name:
                unwanted.append(values)
        photo[i] = [values for values in photo[i] if values not in unwanted]
            
    
    print(photo)

    #Test - dictionary
    for key in name:
        for value in yearning:
         dictionary[key] = value
         yearning.remove(value)
         break

    for i in range(len(photo)):
        for values in photo[i]:
            temp += dictionary[values]
        answer.insert(i,temp)
        temp = 0
    print(answer)
    
    return answer

#Test Case
name = ["may", "kein", "kain", "radi"]
yearning = [5, 10, 1, 3]
photo =[["may", "kein", "kain", "radi"],["may", "kein", "brin", "deny"], ["kon", "kain", "may", "coni"]]
solution(name,yearning,photo)