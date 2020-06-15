from flask import Flask, Response
from flask import request, jsonify
import json
import random
app = Flask(__name__)


class User:
    LOVE_LIST = []
    PUB_LIST = []
    TOT_LIST = []
    LIKE_LIST = []
    user_id = 0
    index = 0

    def UserIndex(self):
        self.TOT_LIST.clear()
        json_data = {
            'id': "11",
            'touxiang': "/images/touxiang.png",
            'name': "张三",
            'class': 'shuma',
            'time': "2020-04-20 21:00:00",
            'png': "/images/iPhone11.png",
            'content': "出售闲置iPhone11 64G一部，品色良好，1月份购于拼多多，原装配件，在保，加我的WX：17811112222，线下交易",
            'likes': 233,
            'error_code': 0
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "12",
            'touxiang': "/images/touxiang2.png",
            'class': 'shuma',
            'name': "李四",
            'time': "2020-04-13 5:00:00",
            'png': "/images/xiaomi10.png",
            'content': "出售小米10一部，价格面谈，加qq12387650987",
            'likes': 12
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "13",
            'touxiang': "/images/touxiang3.png",
            'name': "王五",
            'class': 'tushu',
            'time': "2020-04-14 21:00:00",
            'png': "/images/jiwang.png",
            'content': "计网书，白送，先到先得，加qq1111111111",
            'likes': 2
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "14",
            'touxiang': "/images/touxiang4.png",
            'name': "刘六",
            'class': 'shuma',
            'time': "2020-04-15 21:00:00",
            'png': "/images/sonybd.png",
            'content': "出售索尼bd机一台，九成新，购于天猫旗舰店，400元，加qq123123123",
            'likes': 3
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "11",
            'touxiang': "/images/touxiang.png",
            'name': "张三",
            'class': 'shuma',
            'time': "2020-04-20 21:00:00",
            'png': "/images/iPhone11.png",
            'content': "出售闲置iPhone11 64G一部，品色良好，1月份购于拼多多，原装配件，在保，加我的WX：17811112222，线下交易",
            'likes': 233,
            'error_code': 0
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "12",
            'touxiang': "/images/touxiang2.png",
            'class': 'shuma',
            'name': "李四",
            'time': "2020-04-13 5:00:00",
            'png': "/images/xiaomi10.png",
            'content': "出售小米10一部，价格面谈，加qq12387650987",
            'likes': 12
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "13",
            'touxiang': "/images/touxiang3.png",
            'name': "王五",
            'class': 'tushu',
            'time': "2020-04-14 21:00:00",
            'png': "/images/jiwang.png",
            'content': "计网书，白送，先到先得，加qq1111111111",
            'likes': 2
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "14",
            'touxiang': "/images/touxiang4.png",
            'name': "刘六",
            'class': 'shuma',
            'time': "2020-04-15 21:00:00",
            'png': "/images/sonybd.png",
            'content': "出售索尼bd机一台，九成新，购于天猫旗舰店，400元，加qq123123123",
            'likes': 3
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "11",
            'touxiang': "/images/touxiang.png",
            'name': "张三",
            'class': 'shuma',
            'time': "2020-04-20 21:00:00",
            'png': "/images/iPhone11.png",
            'content': "出售闲置iPhone11 64G一部，品色良好，1月份购于拼多多，原装配件，在保，加我的WX：17811112222，线下交易",
            'likes': 233,
            'error_code': 0
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "12",
            'touxiang': "/images/touxiang2.png",
            'class': 'shuma',
            'name': "李四",
            'time': "2020-04-13 5:00:00",
            'png': "/images/xiaomi10.png",
            'content': "出售小米10一部，价格面谈，加qq12387650987",
            'likes': 12
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "13",
            'touxiang': "/images/touxiang3.png",
            'name': "王五",
            'class': 'tushu',
            'time': "2020-04-14 21:00:00",
            'png': "/images/jiwang.png",
            'content': "计网书，白送，先到先得，加qq1111111111",
            'likes': 2
        }
        self.TOT_LIST.append(json_data)
        json_data = {
            'id': "14",
            'touxiang': "/images/touxiang4.png",
            'name': "刘六",
            'class': 'shuma',
            'time': "2020-04-15 21:00:00",
            'png': "/images/sonybd.png",
            'content': "出售索尼bd机一台，九成新，购于天猫旗舰店，400元，加qq123123123",
            'likes': 3
        }
        self.TOT_LIST.append(json_data)

    def __init__(self, user_id):
        self.user_id = user_id


class Good:
    thumb_number = 233
    good_id = 0

    def f_plus(self):
        self.thumb_number += 1

    def f_minus(self):
        self.thumb_number -= 1

    def __init__(self, good_id):
        self.good_id = good_id


@app.route('/getinfo', methods=['POST'])
def getinfo():
    json_data = request.get_json()
    print(json_data)
    user_id = json_data['userid']
    user_class = User(user_id=user_id)
    data_json = {
        'publish_list': user_class.PUB_LIST,
        'loved_list': user_class.LOVE_LIST,
        'tot_list': user_class.TOT_LIST,
        'like_list': user_class.LIKE_LIST,
        'error_code': 0
    }
    return Response(json.dumps(data_json), mimetype='application/json')


@app.route('/thumbup', methods=['POST'])
def thumb_up():
    json_data = request.get_json()
    user_id = json_data['userid']
    good_id = json_data['goodid']
    user_class = User(user_id=user_id)
    good_class = Good(good_id=good_id)
    if good_id in user_class.LOVE_LIST:
        good_class.f_minus()
        user_class.LOVE_LIST.remove(good_id)
        data_json = {
            'thumbnumber': good_class.thumb_number,
            'error_code': 0
        }
        return Response(json.dumps(data_json), mimetype='application/json')
    else:
        good_class.f_plus()
        user_class.LOVE_LIST.append(good_id)
        data_json = {
            'thumbnumber': good_class.thumb_number,
            'error_code': 0
        }
        return Response(json.dumps(data_json), mimetype='application/json')


@app.route('/love', methods=['POST'])
def love():
    json_data = request.get_json()
    user_id = json_data['userid']
    good_id = json_data['goodid']
    user_class = User(user_id=user_id)
    if good_id in user_class.LOVE_LIST:
        user_class.LOVE_LIST.remove(good_id)
        data_json = {
            'issolve': 0
        }
        return Response(json.dumps(data_json), mimetype='application/json')
    else:
        user_class.LOVE_LIST.append(good_id)
        data_json = {
            'issolve': 1
        }
        return Response(json.dumps(data_json), mimetype='application/json')


@app.route('/publish', methods=['POST'])
def publish():
    json_data = request.get_json()
    user_id = json_data['userid']
    good_info = json_data['goodinfo']
    user_class = User(user_id=user_id)
    user_class.TOT_LIST.insert(0, good_info)
    user_class.PUB_LIST.append(good_info)
    data_json = {
        'success': 1
    }
    return Response(json.dumps(data_json), mimetype='application/json')


@app.route('/delete', methods=['POST'])
def delete():
    json_data = request.get_json()
    good_info = json_data['goodinfo']
    user_id = json_data['userid']
    user_class = User(user_id=user_id)
    user_class.TOT_LIST.remove(good_info)
    user_class.PUB_LIST.remove(good_info)
    data_json = {
        'success': 1
    }
    return Response(json.dumps(data_json), mimetype='application/json')


def main():
    app.run(host='0.0.0.0', port=21241, debug=True)


if __name__ == '__main__':
    user_class = User("114514")
    user_class.UserIndex()
    main()
