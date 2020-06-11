var Realm = require('realm');

const server_address = "INSERT";

async function main() {
    const adminUser = await Realm.Sync.User.login(`https://${server_address}`, 'admin', 'password');
    const realm = await Realm.open({
        sync: {
            user: adminUser,
            url: `realms://${server_address}/aRealm`,
        }
    });

    // Use the Realm for querying or writing to push data to clients
}

main()