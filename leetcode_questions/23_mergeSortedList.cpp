ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> q;

        for(auto head: lists)
        {
            if(head!=NULL)
            {
                q.push({head->val, head});
            }
        }

        while(!q.empty())
        {
            ListNode* newNode = q.top().second;
            q.pop();

            if(newNode->next != NULL)
            {
                q.push({newNode->next->val, newNode->next});
            }
            dummyTail->next = newNode;
            dummyTail = dummyTail->next;
        }
        return dummyHead->next;


        
    }