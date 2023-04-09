vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    int j = n - 1;
    while (j >= 0)
    {
        int temp = arr[j];
        while (st.top() >= temp)
        {
            st.pop();
        }
        ans[j] = st.top();
        st.push(temp);
        j--;
    }
    return ans;
}