import sublist
s = sublist.SubList(range(3))
s.extend(s)
print(len(s))

print(s.increment())

print(s.increment())