#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

class Message {
public:
    std::string msg;
    int id;
    std::set<std::string> likes;
    std::string username;
    Message(int id, std::string msg, std::string username) : id(id), msg(msg), username(username) {}

    void like(std::string username) {
        likes.insert(username);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Message " << this->id << ": " << this->msg << "\n - " << username;
        ss << " - likes: " << likes.size();
        return ss.str();
    }

    int getId() {
        return id;
    }
};

class Inbox {
public:
    std::map<int, Message*> messages;
    std::map<int, Message*> unread;

    Inbox() {};

    std::vector<Message*> getAll() {
        std::vector<Message*> all;
        for (auto const& x : this->messages) {
            all.insert(all.begin(), x.second);
        }
        return all;
    }

    Message* getTweet(int id) {
        return messages[id];
    }

    std::vector<Message*> getUnread() {
        std::vector<Message*> all;
        for (auto const& x : this->unread) {
            all.insert(all.begin(), x.second);
        }
        return all;
    }

    void storeMessage(Message* tweet) {
        messages[tweet->getId()] = tweet;
        unread[tweet->getId()] = tweet;
    }

    void storeUnread(Message* tweet) {
        unread[tweet->getId()] = tweet;
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Inbox: \n";
        for (auto x : this->messages) {
            ss << x.second->toString() << "\n";
        }
        return ss.str();
    }
};

class User {
    Inbox inbox;

public:
    std::string name;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;

    User(std::string name) : name(name) {};

    void follow(User* user) {
        following[user->name] = user;
        user->followers[name] = this;
    }

    Inbox getInbox() {
        return this->inbox;
    }

    void like(int tweetId) {
        inbox.messages[tweetId]->like(name);
    }

    void sendTweet(Message* tweet) {
        this->inbox.storeMessage(tweet);
        for (auto const& x : followers) {
            x.second->inbox.storeUnread(tweet);
        }
    }

    void unfollow(User* user) {
        following.erase(user->name);
        user->followers.erase(name);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "User " << name << "\nFollowers: \n";
        for (auto const& x : followers) {
            ss << x.second->name << " \n";
        }
        ss << "\nFollowing: \n";
        for (auto const& x : following) {
            ss << x.second->name << " \n";
        }
        return ss.str();
    }
};

class Twitter {
    std::map<std::string, User*> users;
    std::map<int, Message*> messages;
    int nxtId = 0;
public:
    Twitter() {};

    void addUser(User* user) {
        users[user->name] = user;
    }

    User* getUser(std::string name) {
        return users[name];
    }

    void sendTweet(std::string username, std::string tweet) {
        messages[nxtId] = new Message(nxtId, tweet, username);
        users[username]->sendTweet(messages[nxtId]);
        nxtId++;
    }

    std::string toString() {
        std::stringstream ss;
        ss << "Twitter: \n";
        for (auto const& x : users) {
            ss << x.second->name << "\n";
        }
        return ss.str();
    }
};

int main() {
    std::cout << "Hello, World!\n";
    Twitter twitter;
    twitter.addUser(new User("alice"));
    twitter.addUser(new User("bob"));
    twitter.sendTweet("alice", "Hello");
    std::cout << twitter.toString();
    twitter.getUser("alice")->follow(twitter.getUser("bob"));
    std::cout << twitter.getUser("alice")->toString();
    std::cout << twitter.getUser("alice")->getInbox().toString();
}