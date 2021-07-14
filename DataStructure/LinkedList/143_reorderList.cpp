

// 把奇数位置和偶数位置分成两条链表
while (cur != NULL && next != NULL) {
    cur->next = next->next;
    if (cur->next != NULL)
        next->next = cur->next->next;
    cur = cur->next;
    next = next->next;
} 