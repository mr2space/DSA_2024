import urllib.request

url = "https://erp.aktu.ac.in/"

run = True;

while run:
    print("scanning")
    try:
        status_code = urllib.request.urlopen(url).getcode()
    except:
        pass
    website_is_up = status_code == 200
    print("up status: ",website_is_up)
    if website_is_up:
        break



# import required module
from playsound import playsound
 
# for playing note.wav file
print('playing sound using  playsound')
playsound(r'C:\Users\princ\OneDrive\Desktop\DSA\result\music.mp3')
