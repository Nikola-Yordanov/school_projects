class Time:
    def __init__(self, hour, minute, second):
        if hour > 23:
            self.__hour = hour - 24 #ne raboti, kogato hour > 2*24
        elif hour <= 0:
            self.__hour = 0
        else: self.__hour = hour

        if minute > 59:
            self.__minute = minute - 60
        elif minute <= 0:
            self.__minute = 0
        else: self.__minute = minute

        if second > 59:
            self.__second = second - 60
        elif second <= 0:
            self.__second = 0
        else: self.__second = second

    def get_hour(self):
        return self.__hour
    def set_hour(self, hour):
        self.__hour = hour

    def get_minute(self):
        return self.__minute
    def set_minute(self, minute):
        self.__minute = minute

    def get_second(self):
        return self.__second
    def set_second(self, second):
        self.__second = second


    hour = property(get_hour, set_hour)
    minute = property(get_minute, set_minute)
    second = property(get_second, set_second)


    def __str__(self):
        if self.__hour < 10:
            hour = "0" + str(self.__hour)
        else: hour = str(self.__hour)
        if self.__minute < 10:
            minute = "0" + str(self.__minute)
        else: minute = str(self.__minute)
        if self.__second < 10:
            second = "0" + str(self.__second)
        else: second = str(self.__second)

        return hour + ":" + minute + ":" + second

    def __add__(self, other):
        self.__hour += other.hour
        self.__minute += other.minute
        self.__second += other.second
        return Time(self.__hour, self.__minute, self.__second)
        
    def __sub__(self, other):
        self.__hour -= other.hour
        self.__minute -= other.minute
        self.__second -= other.second
        return Time(self.__hour, self.__minute, self.__second)




    def next_second(self):

        time1 = Time(self.__hour, self.__minute, self.__second)

        if self.__second == 59:
            time1.second = 00
            if self.__minute == 59:
                time1.minute = 00
                if self.__hour == 23:
                    time1.hour = 00
                else: time1.hour += 1

            else: time1.minute += 1

        else: time1.second += 1

        return time1

    def previous_second(self):

        time = Time(self.__hour, self.__minute, self.__second)

        if self.__second == 00:
            time.second = 59
            if self.__minute == 00:
                time.minute = 59
                if self.__hour == 00:
                    time.hour = 23
                else: time.hour -= 1

            else: time.minute -= 1

        else: time.second -= 1

        return time

time1 = Time(15, 28, 38)