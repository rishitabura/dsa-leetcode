class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int m = meetings.size();

        sort(begin(meetings), end(meetings));

        vector<long long> lastAvailableAt(n, 0);
        vector<int> roomsUsedCount(n, 0);

        for(vector<int>&meet : meetings){

            int start = meet[0];
            int end = meet[1];
            bool found = false;
            int duration = end - start;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;

            for(int room = 0; room<n; room++)
            {
                if(lastAvailableAt[room] <= start)
                {
                    lastAvailableAt[room] = end;
                    roomsUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earlyEndRoomTime){
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom = room;
                }
            }

            if(!found){
                lastAvailableAt[earlyEndRoom] +=  duration;
                roomsUsedCount[earlyEndRoom]++;

            }
        }

        int resultRoom = -1;
        int maxUse = 0;

        for(int room = 0; room < n; room++)
        {
            if(roomsUsedCount[room] > maxUse)
            {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }


        return resultRoom;
    }
};