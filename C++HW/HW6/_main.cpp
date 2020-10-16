#include "gechatuser.h"

int main()
{
    int a = 6;
    cout<<"??"<<endl;
    cout<<a<<endl;
    shared_ptr<GechatUser> gzw(new GechatUser("GeziWang"));
    shared_ptr<GechatUser> gf(new GechatUser("Girlfriend"));
    gzw->addFriend(gf);
    gf->addFriend(gzw);
    gf->doubleDelete(gzw);
    CustomSet<GechatUser> sad_story;
    sad_story.add(*gf);
    sad_story.add(*gzw);
    //sad_story.sortSet();
    sad_story.printSet();
    getchar();
    return 0;
}