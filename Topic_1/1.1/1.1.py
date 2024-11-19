import spam
import sys
status = spam.system("1")
print(sys.getrefcount(status))
