namespace mysharp.DataStructure;
public class Heap {
    private UInt32[] heap;
    public int lastIdx = -1;
    public int Length { get { return heap.Length; }}
    public Heap(int l) => heap = new UInt32[l];

    public bool TryAdd(UInt32 val) {
        if (lastIdx >= heap.Length - 1)
            return false;

        int idx = ++lastIdx;
        heap[idx] = val;
        while (idx > 0) {
            int parentIdx = (idx - 1) / 2;
            if (heap[idx] >= heap[parentIdx]) {
                break;
            }
            UInt32 temp = heap[idx];
            heap[idx] = heap[parentIdx];
            heap[parentIdx] = temp;
            idx = parentIdx;
        }
        return true;
    }

    public bool TryRemove(out UInt32 pop) {
        pop = 0;
        if (lastIdx <= -1)
            return false;

        pop = heap[0];
        heap[0] = heap[lastIdx--];

        int idx = 0;
        while (true) {
            int leftChild = idx * 2 + 1;
            int rightChild = idx * 2 + 2;
            
            if (rightChild <= lastIdx
                && heap[idx] > heap[rightChild]) {
                if (heap[rightChild] > heap[leftChild]) {
                    Swap(ref heap[idx], ref heap[leftChild]);
                    idx = leftChild;
                }
                else {
                    Swap(ref heap[idx], ref heap[rightChild]);
                    idx = rightChild;
                }
            }
            else if (leftChild <= lastIdx
                && heap[idx] > heap[leftChild]) {
                Swap(ref heap[idx], ref heap[leftChild]);
                idx = leftChild;
            }
            else
                break;
        }

        return true;
    }
    public void Swap(ref UInt32 a, ref UInt32 b) {
        UInt32 temp = a;
        a = b;
        b = temp;
    }
}
