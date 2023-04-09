void createBase(vector<int> &base, int row, vector<vector<char>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[row][i] == '1')
            base[i] += 1;
        else
            base[i] = 0;
    }
}
void rightPossible(vector<int> &right, vector<int> &base, int n)
{
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = base[i];
        while (st.top() != -1 && base[st.top()] >= temp)
        {
            st.pop();
        }
        right[i] = st.top();
        st.push(i);
    }
}
void leftPossible(vector<int> &left, vector<int> &base, int n)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int temp = base[i];
        while (st.top() != -1 && base[st.top()] >= temp)
        {
            st.pop();
        }
        left[i] = st.top();
        st.push(i);
    }
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxArea = 0;
    int n = matrix[0].size();
    vector<int> base(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        createBase(base, i, matrix, n);
        leftPossible(left, base, n);
        rightPossible(right, base, n);
        for (int i = 0; i < n; i++)
        {
            int l = base[i];
            if (right[i] == -1)
                right[i] = n;
            int b = right[i] - left[i] - 1;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}