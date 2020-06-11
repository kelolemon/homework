class Solution:
    def simplifyPath(self, path: str) -> str:
        ans = []
        for sub_str in path.split("/"):
            ans = {"": ans, ".": ans, "..": ans[:-1:]}.get(sub_str, ans + [sub_str])
        return "/" + "/".join(ans)


if __name__ == '__main__':
    path = "/home/../a"
    print(Solution().simplifyPath(path))

