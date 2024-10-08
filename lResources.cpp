#include "lResources.h"

lResources *lResources::P()
{
        static lResources This = {};
        return &This;
    }

const QString &lResources::GetResDirPath()
{
        return m_dirPath;
    }

void lResources::getGifFilesFromDirectory(const QString &directoryPath, const QString &_filters, QStringList &_buffer)
{
       QDir directory(directoryPath);
       // 按文件名排序
       directory.setSorting(QDir::Name);
       // 设置过滤器，只选择文件且扩展名为.gif
       directory.setNameFilters(QStringList() << "*" + _filters);
       directory.setFilter(QDir::Files);
       // 遍历目录中的所有文件
       foreach (QFileInfo fileInfo, directory.entryInfoList()) {
           _buffer << fileInfo.absoluteFilePath(); // 将文件的绝对路径添加到QStringList中
           qDebug() << fileInfo.absoluteFilePath();
       }
}

void lResources::Init_Gif()
{
        getGifFilesFromDirectory(m_dirPath + "/daiji",".gif",m_gif_daiji);
        getGifFilesFromDirectory(m_dirPath + "/dongzuo",".gif",m_gif_dongzuo);
    }

QString lResources::GetGif(ENUM_PET_STATUS _type, int _index)
{
        QStringList* _p = nullptr;
        switch (_type) {
        case ENUM_PET_STATUS::_DAIJI:
            _p = &m_gif_daiji;
            break;
        case ENUM_PET_STATUS::_DONGZUO:
            _p = &m_gif_dongzuo;
            break;
        default:
            return QString();
            break;
        }

//        if(_p->size() < 1){
//            QMessageBox::warning(nullptr,u8"错误",u8"资源未初始化!",QMessageBox::Ok);
//            return QString();
//        }
        if(_index != -1){
            return _p->at(_index);
        }
        return _p->at(QRandomGenerator::global()->bounded(_p->size() -1));
    }

int lResources::GetSleepTimeLength(int _min, int _max)
{
    return QRandomGenerator::global()->bounded(_max - _min) + _min;
}

const QString &lResources::GetStartMsg()
{
    static const QStringList msgList = {
        u8"主人! 终于见到您了!",
        u8"我又回来啦,lalala...",
        u8"刚才抓了一只大青蛙,好大!",
        u8"今天的天气真不错，适合出去走走。",
        u8"我刚刚学会了一个新技能，好开心！",
        u8"主人，您今天心情怎么样？",
        u8"我昨晚做了一个奇怪的梦，梦见我们在海边玩耍。",
        u8"主人，您有什么想和我分享的吗？",
        u8"我刚刚发现了一个有趣的小游戏，我们一起玩吧！",
        u8"主人，您今天有什么计划吗？",
        u8"我刚刚看到了一只可爱的小猫，好想抱抱它！",
        u8"主人，您觉得今天的晚餐吃什么好呢？",
        u8"我刚刚听到了一首很好听的歌，我们一起听听吧！",
        u8"主人，您今天工作/学习累了吗？需要我帮您放松一下吗？",
        u8"我刚刚看到了一篇很有趣的文章，我们一起看看吧！",
        u8"主人，您今天有什么新鲜事要和我分享吗？",
        u8"我刚刚学会了一道新菜，下次做给您尝尝吧！",
        u8"主人，您今天有什么需要我帮忙的吗？",
        u8"我刚刚看到了一部很好看的电影，我们一起看看吧！",
        u8"主人，您今天有什么特别的安排吗？",
        u8"我刚刚发现了一个很棒的旅游景点，我们一起去看看吧！",
        u8"主人，您今天有什么想要实现的愿望吗？",
        u8"我刚刚学会了一种新的语言，我们一起练习吧！",
        u8"主人，您今天有什么想要了解的知识吗？",
        u8"我刚刚看到了一本很有趣的书，我们一起读读吧！",
        u8"主人，您今天有什么想要尝试的新事物吗？",
        u8"我刚刚学会了一种新的运动，我们一起试试吧！",
        u8"主人，您今天有什么想要挑战的目标吗？",
        u8"我刚刚看到了一个很有趣的展览，我们一起看看吧！",
        u8"主人，您今天有什么想要分享的快乐吗？",
        u8"我刚刚学会了一种新的乐器，我们一起演奏吧！",
        u8"主人，您今天有什么想要实现的梦想吗？",
        u8"我刚刚看到了一个很有趣的节目，我们一起看看吧！",
        u8"主人，您今天有什么想要探索的新领域吗？",
        u8"我刚刚学会了一种新的艺术形式，我们一起创作吧！",
        u8"主人，您今天有什么想要实现的计划吗？",
        u8"我刚刚看到了一个很有趣的挑战，我们一起试试吧！",
        u8"主人，您今天有什么想要分享的成就吗？",
        u8"我刚刚学会了一种新的技能，我们一起展示吧！",
        u8"主人，您今天有什么想要实现的愿望吗？",
        u8"我刚刚看到了一个很有趣的活动，我们一起参加吧！",
        u8"主人，您今天有什么想要探索的新世界吗？",
        u8"我刚刚学会了一种新的交流方式，我们一起试试吧！",
        u8"主人，您今天有什么想要分享的喜悦吗？",
        u8"我刚刚看到了一个很有趣的项目，我们一起参与吧！",
        u8"主人，您今天有什么想要实现的梦想吗？",
        u8"我刚刚学会了如何更好地理解您，我们一起成长吧！",
        u8"主人，您今天有什么想要分享的感动吗？",
        u8"我刚刚看到了一个很有趣的机会，我们一起抓住吧！",
        u8"主人，您今天有什么想要探索的新领域吗？",
        u8"我刚刚学会了一种新的表达方式，我们一起尝试吧！",
        u8"主人，您今天有什么想要分享的快乐吗？",
        u8"我刚刚看到了一个很有趣的挑战，我们一起迎接吧！",
        u8"主人，您今天有什么想要实现的梦想吗？",
        u8"我刚刚学会了如何更好地支持您，我们一起前进吧！",
        u8"主人，您今天有什么想要分享的成就吗？",
        u8"我刚刚看到了一个很有趣的机会，我们一起把握吧！"
    };
    return msgList.at(QRandomGenerator::global()->bounded(msgList.size() - 1));
}

const QString &lResources::GetMsg_daiji()
{
    static const QStringList msgList = {
        "好无聊呀!",
        "好饿......",
        "我想睡觉了...",
        "一闪一闪亮晶晶...",
        "主人,你知道猴子是什么变的吗？",
        "做个梦...",
        "今天的天气真好！",
        "我有点想出去玩...",
        "你知道吗？猫头鹰是夜行性动物。",
        "我昨晚做了一个奇怪的梦。",
        "主人，你会做菜吗？",
        "我听说大海很美，真想去看看。",
        "你知道星星为什么会闪烁吗？",
        "我有点口渴了...",
        "主人，你最喜欢的颜色是什么？",
        "我听说读书可以让人变得更聪明。",
        "你知道吗？大象是世界上最大的陆生动物。",
        "我有点累了，想休息一下。",
        "主人，你最喜欢的电影是什么？",
        "我听说音乐可以治愈心灵。",
        "你知道吗？企鹅不会飞，但它们是游泳高手。",
        "我有点饿了，想吃点东西。",
        "主人，你最喜欢的书是什么？",
        "我听说旅行可以开阔视野。",
        "你知道吗？长颈鹿的脖子很长，但它们只有七个颈椎。",
        "我有点困了，想打个盹。",
        "主人，你最喜欢的食物是什么？",
        "我听说瑜伽可以让人身心放松。",
        "你知道吗？蜜蜂是勤劳的传粉者。",
        "我有点冷，想找个暖和的地方。",
        "主人，你最喜欢的季节是什么？",
        "我听说绘画可以表达内心的情感。",
        "你知道吗？海豚是非常聪明的海洋生物。",
        "我有点无聊，想找点事情做。",
        "主人，你最喜欢的运动是什么？",
        "我听说写作可以记录生活的点滴。",
        "你知道吗？北极熊是极地的霸主。",
        "我有点热，想找个凉快的地方。",
        "主人，你最喜欢的节日是什么？",
        "我听说摄影可以捕捉美丽的瞬间。",
        "你知道吗？袋鼠是澳大利亚的象征。",
        "我有点害怕，想找个安全的地方。",
        "主人，你最喜欢的动物是什么？",
        "我听说舞蹈可以释放压力。",
        "你知道吗？狮子是草原的王者。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的游戏是什么？",
        "我听说园艺可以让人心情愉悦。",
        "你知道吗？熊猫是中国的国宝。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的歌曲是什么？",
        "我听说冥想可以提高专注力。",
        "你知道吗？鲸鱼是海洋的巨人。",
        "我有点好奇，想了解更多知识。",
        "主人，你最喜欢的城市是什么？",
        "我听说烹饪可以培养创造力。",
        "你知道吗？考拉是澳大利亚的萌物。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的电视剧是什么？",
        "我听说阅读可以拓宽视野。",
        "你知道吗？猎豹是陆地上跑得最快的动物。",
        "我有点迷茫，想找个方向。",
        "主人，你最喜欢的饮料是什么？",
        "我听说旅行可以增长见识。",
        "你知道吗？骆驼是沙漠之舟。",
        "我有点孤独，想找个陪伴。",
        "主人，你最喜欢的艺术家是谁？",
        "我听说学习新技能可以保持年轻。",
        "你知道吗？猴子是人类的近亲。",
        "我有点焦虑，想找个平静的方式。",
        "主人，你最喜欢的历史人物是谁？",
        "我听说志愿服务可以带来满足感。",
        "你知道吗？蝴蝶是美丽的蜕变者。",
        "我有点沮丧，想找个振作的方式。",
        "主人，你最喜欢的科学发现是什么？",
        "我听说种植植物可以净化空气。",
        "你知道吗？章鱼是海洋的智者。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的神话故事是什么？",
        "我听说练习乐器可以培养耐心。",
        "你知道吗？犀牛是濒危的巨兽。",
        "我有点好奇，想了解更多文化。",
        "主人，你最喜欢的自然景观是什么？",
        "我听说徒步旅行可以亲近自然。",
        "你知道吗？海龟是长寿的象征。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的诗歌是什么？",
        "我听说瑜伽可以提高灵活性。",
        "你知道吗？狼是群居的领袖。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的发明是什么？",
        "我听说绘画可以表达个性。",
        "你知道吗？鹰是天空的霸主。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说写作可以记录灵感。",
        "你知道吗？河马是水中的巨兽。",
        "我有点好奇，想了解更多艺术。",
        "主人，你最喜欢的建筑是什么？",
        "我听说园艺可以培养耐心。",
        "你知道吗？松鼠是森林的精灵。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的历史事件是什么？",
        "我听说冥想可以提高意识。",
        "你知道吗？鳄鱼是沼泽的霸主。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学理论是什么？",
        "我听说摄影可以捕捉情感。",
        "你知道吗？狐狸是狡猾的象征。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的文学作品是什么？",
        "我听说舞蹈可以表达情感。",
        "你知道吗？熊是森林的守护者。",
        "我有点好奇，想了解更多自然。",
        "主人，你最喜欢的音乐风格是什么？",
        "我听说学习外语可以开阔思维。",
        "你知道吗？鹿是森林的优雅者。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的运动项目是什么？",
        "我听说烹饪可以享受生活。",
        "你知道吗？蛇是神秘的象征。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的电影类型是什么？",
        "我听说园艺可以享受宁静。",
        "你知道吗？鸟是天空的使者。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的节日传统是什么？",
        "我听说绘画可以释放创造力。",
        "你知道吗？鱼是水中的精灵。",
        "我有点好奇，想了解更多科技。",
        "主人，你最喜欢的历史时期是什么？",
        "我听说写作可以记录成长。",
        "你知道吗？昆虫是生态系统的重要组成部分。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的艺术形式是什么？",
        "我听说冥想可以提高自我意识。",
        "你知道吗？鲸鱼是海洋的守护者。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学发现是什么？",
        "我听说摄影可以捕捉美丽。",
        "你知道吗？猴子是人类的近亲。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说舞蹈可以表达自由。",
        "你知道吗？狮子是草原的王者。",
        "我有点好奇，想了解更多文化。",
        "主人，你最喜欢的自然景观是什么？",
        "我听说徒步旅行可以亲近自然。",
        "你知道吗？海龟是长寿的象征。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的诗歌是什么？",
        "我听说瑜伽可以提高灵活性。",
        "你知道吗？狼是群居的领袖。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的发明是什么？",
        "我听说绘画可以表达个性。",
        "你知道吗？鹰是天空的霸主。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说写作可以记录灵感。",
        "你知道吗？河马是水中的巨兽。",
        "我有点好奇，想了解更多艺术。",
        "主人，你最喜欢的建筑是什么？",
        "我听说园艺可以培养耐心。",
        "你知道吗？松鼠是森林的精灵。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的历史事件是什么？",
        "我听说冥想可以提高意识。",
        "你知道吗？鳄鱼是沼泽的霸主。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学理论是什么？",
        "我听说摄影可以捕捉情感。",
        "你知道吗？狐狸是狡猾的象征。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的文学作品是什么？",
        "我听说舞蹈可以表达情感。",
        "你知道吗？熊是森林的守护者。",
        "我有点好奇，想了解更多自然。",
        "主人，你最喜欢的音乐风格是什么？",
        "我听说学习外语可以开阔思维。",
        "你知道吗？鹿是森林的优雅者。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的运动项目是什么？",
        "我听说烹饪可以享受生活。",
        "你知道吗？蛇是神秘的象征。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的电影类型是什么？",
        "我听说园艺可以享受宁静。",
        "你知道吗？鸟是天空的使者。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的节日传统是什么？",
        "我听说绘画可以释放创造力。",
        "你知道吗？鱼是水中的精灵。",
        "我有点好奇，想了解更多科技。",
        "主人，你最喜欢的历史时期是什么？",
        "我听说写作可以记录成长。",
        "你知道吗？昆虫是生态系统的重要组成部分。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的艺术形式是什么？",
        "我听说冥想可以提高自我意识。",
        "你知道吗？鲸鱼是海洋的守护者。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学发现是什么？",
        "我听说摄影可以捕捉美丽。",
        "你知道吗？猴子是人类的近亲。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说舞蹈可以表达自由。",
        "你知道吗？狮子是草原的王者。",
        "我有点好奇，想了解更多文化。",
        "主人，你最喜欢的自然景观是什么？",
        "我听说徒步旅行可以亲近自然。",
        "你知道吗？海龟是长寿的象征。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的诗歌是什么？",
        "我听说瑜伽可以提高灵活性。",
        "你知道吗？狼是群居的领袖。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的发明是什么？",
        "我听说绘画可以表达个性。",
        "你知道吗？鹰是天空的霸主。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说写作可以记录灵感。",
        "你知道吗？河马是水中的巨兽。",
        "我有点好奇，想了解更多艺术。",
        "主人，你最喜欢的建筑是什么？",
        "我听说园艺可以培养耐心。",
        "你知道吗？松鼠是森林的精灵。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的历史事件是什么？",
        "我听说冥想可以提高意识。",
        "你知道吗？鳄鱼是沼泽的霸主。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学理论是什么？",
        "我听说摄影可以捕捉情感。",
        "你知道吗？狐狸是狡猾的象征。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的文学作品是什么？",
        "我听说舞蹈可以表达情感。",
        "你知道吗？熊是森林的守护者。",
        "我有点好奇，想了解更多自然。",
        "主人，你最喜欢的音乐风格是什么？",
        "我听说学习外语可以开阔思维。",
        "你知道吗？鹿是森林的优雅者。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的运动项目是什么？",
        "我听说烹饪可以享受生活。",
        "你知道吗？蛇是神秘的象征。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的电影类型是什么？",
        "我听说园艺可以享受宁静。",
        "你知道吗？鸟是天空的使者。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的节日传统是什么？",
        "我听说绘画可以释放创造力。",
        "你知道吗？鱼是水中的精灵。",
        "我有点好奇，想了解更多科技。",
        "主人，你最喜欢的历史时期是什么？",
        "我听说写作可以记录成长。",
        "你知道吗？昆虫是生态系统的重要组成部分。",
        "我有点疲惫，想找个休息的方式。",
        "主人，你最喜欢的艺术形式是什么？",
        "我听说冥想可以提高自我意识。",
        "你知道吗？鲸鱼是海洋的守护者。",
        "我有点紧张，想找个放松的方式。",
        "主人，你最喜欢的科学发现是什么？",
        "我听说摄影可以捕捉美丽。",
        "你知道吗？猴子是人类的近亲。",
        "我有点兴奋，想找个分享的方式。",
        "主人，你最喜欢的哲学思想是什么？",
        "我听说舞蹈可以表达自由。"
    };
    return msgList.at(QRandomGenerator::global()->bounded(msgList.size() - 1));
}

const QString &lResources::GetMsg_shaking()
{
    static const QStringList msgList = {
        u8"你不太聪明的样子......",
        u8"从前...额...刚想唱首歌...",
        u8"少摸摸，我词穷...",
        u8"你能把我摸到词穷吗？",
        u8"怎么了？我刚准备跳个舞~",
        u8"嘿！嘿！干嘛捏。。。",
        u8"别急，我正在思考人生",
        u8"哇，你点的菜看起来真好吃！",
        u8"今天的天气真不错，适合出去走走",
        u8"你知道吗？我昨晚做了一个奇怪的梦",
        u8"嘿，猜猜我在哪里？",
        u8"我刚刚学会了一个新技能，想看看吗？",
        u8"有时候，我觉得自己像个超级英雄",
        u8"你知道吗？我最喜欢的一首歌是...",
        u8"嘿，你觉得我应该换个发型吗？",
        u8"我刚刚发现了一个秘密基地，你想去看看吗？",
        u8"有时候，我觉得自己像个探险家",
        u8"你知道吗？我最喜欢的一本书是...",
        u8"嘿，你觉得我应该学点什么新东西？",
        u8"我刚刚发现了一个新的游戏，你想一起玩吗？",
        u8"有时候，我觉得自己像个艺术家",
        u8"你知道吗？我最喜欢的一部电影是..."
        ,u8"你 你 你..."
        ,u8"你，gun去忙!"
        ,u8"要抱抱......"
        ,u8"这么喜欢摸我？"
        ,u8"你说花儿为什么这样红？"
        ,u8"我生气的话后果很严重的~~~"
        ,u8"唉唉唉 别晃!"
        ,u8"我可分不清东南西北..."
        ,u8"这边好像是西边?"
        , u8"这边看看?"
        ,u8"好痒 好痒 讨厌！"
        ,u8"生气，别碰我!"
        ,u8"往哪滑呢？？？"
        ,u8"哎呀呀呀呀!!!"
        ,u8"你  走开..."
        ,u8"小拳拳锤死你!"
    };
    return msgList.at(QRandomGenerator::global()->bounded(msgList.size() - 1));
}

const QString &lResources::GetMsg_dongzuo()
{
    static const QStringList msgList = {
        "动恰恰，动恰恰...",
        "一起来跳支舞吧!",
        "快来欣赏我的舞蹈吧!",
        "跟着节奏摇摆!",
        "舞动你的身体!",
        "让我们一起享受音乐和舞蹈的乐趣!",
        "邀请你的朋友一起加入舞蹈派对!",
        "用舞蹈表达你的情感!",
        "在舞池中尽情释放自己!",
        "感受音乐的脉动，一起跳舞吧!",
        "让我们用舞蹈连接彼此的心灵!",
        "跳出你的舒适区，尝试新的舞步!",
        "在舞蹈中找到快乐和自由!",
        "用舞蹈讲述你的故事!",
        "让舞蹈成为我们共同的记忆!",
        "在舞蹈的世界里，没有界限和束缚!",
        "用舞蹈传递爱与和平的信息!",
        "在舞蹈中找到你的节奏和韵律!",
        "让每一次舞动都充满激情和活力!",
        "用舞蹈点亮生活的每一个角落!"
    };
    return msgList.at(QRandomGenerator::global()->bounded(msgList.size() - 1));
}
