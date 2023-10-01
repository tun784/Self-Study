import pyttsx3
import datetime
import speech_recognition

robot_input = speech_recognition.Recognizer()
robot_output = pyttsx3.init()
robot_AI = " -_- "

with speech_recognition.Microphone() as mic:
    print("Robot: I'm hearing you...")
    audio = robot_input.listen(mic)
    
print("Robot: ...")

try:
    user = robot_input.recognize_google(audio)
except:
    user = "*Invalid sounds*"
    