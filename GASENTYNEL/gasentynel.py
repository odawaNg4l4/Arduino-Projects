import africastalking
import serial

threshold_temperature = 30
threshold_humidity = 60
threshold_ppm = 70

arduino = serial.Serial(port='COM8', baudrate=9600, timeout=.1)

# Initialize Africa's Talking
africastalking.initialize(
    username='ujumbehealth',
    api_key='7b096f3098087abbc58d328376e591229fd908d043cb5cca7f409f53adb95c39'
)
sms = africastalking.SMS

def sending(message):
    # Set the numbers in international format
    recipients = ["+254721333151"]
    # Set your message
    try:
        # Send the message
        response = sms.send(message, recipients)
        print(response)
    except Exception as e:
        print(f'Houston, we have a problem: {e}')

while True:
    data = arduino.readline().decode('utf-8')
    [humidity,temperature,ppm] = [int(i) for i in data.split(',')]
    print (data)
    
    
    if(temperature>threshold_temperature or humidity>threshold_humidity):
        sending("Help!! I'm hot & wet")
