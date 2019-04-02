import pyvjoy, sys
import time
vj = pyvjoy.vJoy()
vj.capture(1)
js = pyvjoy.Joystick()
maxval = 32750
time.sleep(3.0)
for steer in range(0,maxval,50):
    js.setAxisY(steer)
    vj.update(js)
    time.sleep(0.1)
