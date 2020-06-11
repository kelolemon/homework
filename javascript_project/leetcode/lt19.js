

function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let first = head;
    let second = head;
    let last_second = null;
    for (let i = 1; i < n; i++) {
        first = first.next;
    }
    while (first.next !== null) {
        first = first.next;
        last_second = second;
        second = second.next;
    }
    last_second !== null ? last_second.next = second.next === null ? null : second.next : head = second.next;
    return head;
};
