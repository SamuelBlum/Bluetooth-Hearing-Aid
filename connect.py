import bluetooth, subprocess, os
nearby_devices = bluetooth.discover_devices(duration=4,lookup_names=True,
                                                      flush_cache=True, lookup_class=False)

print("found %d devices" % len(nearby_devices))

for name, addr in nearby_devices:
     print(" %s - %s" % (addr, name))
     name = name      # Device name
     addr = addr      # Device Address

     # kill any "bluetooth-agent" process that is already running
     # subprocess.call("kill -9 `pidof bluetooth-agent`",shell=True)

     os.system("bluetoothctl")
     os.system("bluetoothctl scan on")
     os.system("bluetoothctl pair " + addr)
     os.system("bluetoothctl connect " + addr)
     #subprocess.call("scan off",shell=True)
