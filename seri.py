import serial
import time
import speech_recognition as sr

def recognizer():
    rec = sr.Recognizer()
    with sr.Microphone() as source:
        print('Говорите...')
        rec.pause_threshold = 1
        rec.adjust_for_ambient_noise(source, duration=1)
        audio = rec.listen(source)
    try:
        text = rec.recognize_google(audio, language="ru-RU").lower()
        print(text)
    except sr.UnknownValueError:
        text = 'Не понимаю. Повторите.'
        print(text)
        text = recognizer()
    return text
def stop():
    if ser.is_open:
        ser.close()
        print("Serial connection closed.")
        exit()
def recognize():
    text = recognizer()
    print("Вы сказали:\n", text)
    if text == 'печать':
        print("Готовлюсь к печати...")
        pr = recognizer()
        print("Печатаю: \n",pr)
        return pr

    elif text == 'стоп':
        return stop()
    return text

letter_dick = {
            'а' : [1,0],
            'б' : [3,0],
            'в' : [2,7],
            'г' : [3,3],
            'д' : [1,3],
            'е' : [1,2],
            'ё' : [1,4],
            'ж' : [2,3],
            'з' : [5,6],
            'и' : [2,1],
            'к' : [5,0],
            'л' : [7,0],
            'м' : [5,1],
            'н' : [5,3],
            'о' : [5,2],
            'п' : [7,1],
            'р' : [7,2],
            'с' : [6,1],
            'т' : [6,3],
            'у' : [5,4],
            'ф' : [3,1],
            'х' : [3,2],
            'ц' : [1,1],
            'ч' : [7,3],
            'ш' : [1,6],
            'щ' : [5,5],
            'ъ' : [7,6],
            'ы' : [6,5],
            'ь' : [6,7],
            'э' : [2,5],
            'ю' : [3,6],
            'я' : [3,5],
            ' ' : [0,0],
        }
speech = recognize()




port = "COM4"
baudrate = 9600

try:
    ser = serial.Serial(port, baudrate=baudrate)
    print("Serial connection established.")

    for i in speech:
        command = str(letter_dick[i][0])
        ser.write(command.encode())
        time.sleep(5)
        ser.write("8".encode())
        time.sleep(5)

        command = str(letter_dick[i][1])
        ser.write(command.encode())
        time.sleep(5)
        ser.write("8".encode())
        time.sleep(5)
    print("Печать окончена.")

except serial.SerialException as se:
    print("Serial port error:", str(se))
except Exception as  e:
    print(e)
except KeyboardInterrupt:
    pass

finally:
    # Close the serial connection
    if ser.is_open:
        ser.close()
        print("Serial connection closed.")






        # ser.write(command.encode())
            # line = ser.readline().decode().strip()
            # if line:
            #     print(line)
            #     user_data = str(letter_dick[i][1])
            #     ser.write(user_data.encode())

















        # for i in speech:
        #     user_data = str(letter_dick[i][0])
        #     ser.write(user_data.encode())
        #     print(user_data)
        #
        #     time.sleep(500)
        #
        #     line = ser.readline().decode().strip()
        #     if line:
        #         print(line)
        #         user_data = str(letter_dick[i][1])
        #         ser.write(user_data.encode())