class Solution(object):
    def secondsBetweenTimes(self, startTime, endTime):
        """
        :type startTime: str
        :type endTime: str
        :rtype: int
        """
        st = list(map(int,startTime.split(":")))
        et = list(map(int,endTime.split(":")))

        time1 = st[0] * 60 * 60 + st[1] * 60 + st[2]
        time2 = et[0] * 60 * 60 + et[1] * 60 + et[2]

        return time2-time1
        