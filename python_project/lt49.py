from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = {}
        sort_string = ["".join(sorted(string)) for string in strs]
        for i in range(0, len(sort_string)):
            if sort_string[i] in hash_map:
                hash_map[sort_string[i]].append(strs[i])
            else:
                hash_map[sort_string[i]] = [strs[i]]
        return [x for x in hash_map.values()]


if __name__ == '__main__':
    a = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(Solution().groupAnagrams(a))
