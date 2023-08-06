import IntroduceClasses as Ic

class YourProgram:
    def Camry():
        camry = Ic.Car()
        camry.setModel("Camry")
        camry.setYear(2008)
        
        camry.printDiscription()
        
    def Ford():
        ford = Ic.Car() 
        ford.setModel("Ford")
        ford.setYear(2008)
        
        ford.printDiscription()
        
        
YourProgram.Camry()
YourProgram.Ford()
YourProgram.Camry()
