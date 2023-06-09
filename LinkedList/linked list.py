class Node:
   def __init__(self, value):
      self.data = value
      self.next = None


class LinkList:
   def __init__(self):
      self.start = None

   def insertLast(self, value):
      temp = self.start

      newNode = Node(value)

      if self.start == None:
         self.start = newNode
         
      
      else:
         temp = self.start

         while temp.next != None:
            temp = temp.next
         temp.next = newNode
         
   def print_list(self):
      if self.start is None:
         print("List is empty!")

      itr = self.start
      
      while itr:
         print(str(itr.data) + "-->", end="") 
         itr = itr.next
      print("Null")

chain = LinkList()

chain.insertLast(3)
chain.insertLast(4)
chain.print_list()
