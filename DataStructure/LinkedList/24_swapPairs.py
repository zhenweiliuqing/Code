# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        first_node = head
        second_node = head.next

        # 妙啊 ！！！ 从后往前换！！
        first_node.next = self.swapPairs(second_node.next) 
        second_node.next = first_node

        return second_node


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head

        prev_node = dummy

        while head and head.next:
            # 定义两个节点
            first_node = head
            second_node = head.next
            # 交换两个节点 换3条线
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            prev_node = first_node
            head = first_node.next
        return dummy.next
