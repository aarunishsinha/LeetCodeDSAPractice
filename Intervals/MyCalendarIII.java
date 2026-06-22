class MyCalendarThree {
    private TreeMap<Integer, Integer> timeline;

    public MyCalendarThree() {
        timeline = new TreeMap<>();
    }
    
    public int book(int startTime, int endTime) {
        timeline.put(startTime, timeline.getOrDefault(startTime, 0) + 1);
        timeline.put(endTime, timeline.getOrDefault(endTime, 0) - 1);
        
        int currRooms = 0;
        int maxRooms = 0;
        
        for (int delta : timeline.values()) {
            currRooms += delta;
            maxRooms = Math.max(maxRooms, currRooms);
        }
        
        return maxRooms;
    }
}