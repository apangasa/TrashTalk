import serial
import time

PORT = 'COM3'
BAUDRATE = 9600
CURR_STATE = 0

arduino = serial.Serial(port=PORT, baudrate=BAUDRATE, timeout=.1)


def check_file():
    global CURR_STATE

    commands = None
    with open('./Backend/commands.data', 'r') as comm_file:
        commands = comm_file.read()

    if not len(commands):
        return None

    if int(commands[-1]) != CURR_STATE:
        print('Updating state...')
        CURR_STATE = int(commands[-1])
        return commands[-1]


def write(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(1)
    data = arduino.readline()
    print(data)
    return


def main():
    while True:
        data = check_file()
        if data is not None:
            write(data)


if __name__ == '__main__':
    main()
