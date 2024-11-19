import custom2
def nnn():
    mycustom = custom2.Custom("ding", 'qiuran', 4)
    mycustom2=custom2.Custom("ding", 'qiuran', 5)
    #print(mycustom)
    # print(mycustom==mycustom2)
    # print(mycustom <mycustom2)
    custom2.my_function(mycustom)
    custom2.my_function(1)

    return 0
nnn()

