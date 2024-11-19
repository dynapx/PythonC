#import gc
import custom2
def nnn():
    mycustom = custom2.Custom("ding", 'qiuran', 4)
    mycustom.first = mycustom
    # print(mycustom.first)

    del mycustom
#gc.collect()
nnn()
print(1)





