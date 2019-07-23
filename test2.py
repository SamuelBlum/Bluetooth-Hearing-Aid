from gattlib import GATTRequester, GATTResponse

class NotifyYourName(GATTResponse):
    def on_response(self, name):
        print("your name is: {}".format(name))

response = NotifyYourName()
req = GATTRequester("00:11:22:33:44:55") # use your address here
req.read_by_handle_async(0x12, response)

while True:
    # here, do other interesting things
    sleep(1)
