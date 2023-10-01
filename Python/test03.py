import sys
import math
import pyttsx3
from datetime import datetime, date
import speech_recognition

robot_input = speech_recognition.Recognizer()
robot_output = pyttsx3.init()
robot_AI = "Unknown"
user = "..."

def inputFunction():
    user = input("Ask me anything: ")
    return user
def outputFunction(answer):
    print("Chatbot: " + answer)
    robot_output.say(answer)
    robot_output.runAndWait()
    
def AI_Function(prompt):
    if prompt == "":
        robot_AI = "I can't hear what did you say, try again."
    elif "hello" in prompt:
        robot_AI = "Hello guys"
    elif "today" in prompt:
        today = date.today()
        robot_AI = today.strftime("%B %d, %Y")
    elif "time" in prompt:
        now = datetime.now()
        robot_AI = now.strftime("%H hours %M minutes %S seconds")
    elif "name" in prompt:
        robot_AI = "The name of owner's code is Nguyen Hoang Tuan"
    elif prompt == "exit":
        print("Exiting the program")
        outputFunction()
        sys.exit()
    else:
        robot_AI = "I don't understand what did you say, try again."
        
    return robot_AI

def main():
    while 1==1:
        user = input("Ask me anything: ")
        
        # print("Do you want to use micro or keyboard ?")
        # option = int(input("1/0: "))
        # if option == 1:
        #     user = input("Ask me anything: ")
        # else:
        #     with speech_recognition.Microphone() as mic:
        #         print("Chatbot: I'm hearing you...")
        #         audio = robot_input.listen(mic)
        #     print("Robot: ...")
        #     try:
        #         user = robot_input.recognize_google(audio)
        #     except:
        #         user = "*Invalid sounds*"]        
        #print("User: " + user)
        question = inputFunction()
        AI_Function(question)
        outputFunction()
        
if __name__ == "__main__":
    main()