import math

def num_2_ip(num):
    ip = ''
    for i in range(0,4):
        now = num % 256
        ip = str(now)+ip
        num = num / 256
        if i < 3:
            ip = '.' + ip
    return ip

def ip_2_num(ip):
    a = 0
    for s in ip.split('.'):
        a = a*256 + int(s)
    return a



def ip_2_cidr(start_ip, end_ip):
    masks = [0x00000000, 0x80000000,
             0xC0000000, 0xE0000000, 0xF0000000, 0xF8000000, 0xFC000000,
             0xFE000000, 0xFF000000, 0xFF800000, 0xFFC00000, 0xFFE00000,
             0xFFF00000, 0xFFF80000, 0xFFFC0000, 0xFFFE0000, 0xFFFF0000,
             0xFFFF8000, 0xFFFFC000, 0xFFFFE000, 0xFFFFF000, 0xFFFFF800,
             0xFFFFFC00, 0xFFFFFE00, 0xFFFFFF00, 0xFFFFFF80, 0xFFFFFFC0,
             0xFFFFFFE0, 0xFFFFFFF0, 0xFFFFFFF8, 0xFFFFFFFC, 0xFFFFFFFE,
             0xFFFFFFFF]
    cidrs = []
    start, end = ip_2_num(start_ip), ip_2_num(end_ip)

    while start <= end:
        valid_bits = 32
        while valid_bits > 0:
            if start & masks[valid_bits - 1] != start:
                break
            valid_bits -= 1

        diff = end - start + 1
        diff_bits = int(math.log(diff, 2))
        same_bits = 32 - diff_bits
        cidr_bits = max(same_bits, valid_bits)
        print 'bit: ', same_bits , valid_bits

        cidrs.append(num_2_ip(start) + '/' + str(cidr_bits))
        start += 2 ** (32 - cidr_bits)

    return cidrs

print ip_2_cidr('128.0.0.4', '128.0.0.7')

print ip_2_cidr('255.0.0.7', '255.0.0.19')

print ip_2_cidr('1.1.1.0', '1.1.1.7')
