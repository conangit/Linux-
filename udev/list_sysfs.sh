#!/bin/bash
#
# 遍历整个sysfs中的块设备 字符设备
#

for i in /sys/block/*/dev sys/block/*/*/dev
do
    if [ -f $i ]
    then
        MAJOR=$(sed 's/:.*//' < $i)
        MINOR=$(sed 's/.*://' < $i)
        DEVNAME=$(echo $i | sed -e 's@/dev@@' -e 's@.*/@@')
        echo /dev/$DEVNAME b $MAJOR $MINOR
    fi
done

:<<-EOF
for i in /sys/bus/*/devices/*/dev sys/class/*/*/dev
do
    if [ -f $i ]
    then
        MAJOR=$(sed 's/:.*//' < $i)
        MINOR=$(sed 's/.*://' < $i)
        DEVNAME=$(echo $i | sed -e 's@/dev@@' -e 's@.*/@@')
        echo /dev/$DEVNAME c $MAJOR $MINOR
    fi
done
-EOF
