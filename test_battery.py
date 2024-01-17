import asyncio
import platform
from bleak import BleakClient
import datetime

MAC_ADDRESS = "37D48F6F-C3E1-745F-7CB7-BC87B452F40B"
BATTERY_CHARACTERISTIC_UUID = "00002a19-0000-1000-8000-00805f9b34fb"


def battery_notification_handler(sender, data):
    s = int.from_bytes(data, "little")
    print("{0}: {1}".format(datetime.datetime.now(), s))


async def run(address, loop):
    async with BleakClient(address, loop=loop) as client:
        x = await client.is_connected()
        # for service in client.services:
        #    print("[Service] %s", service)

        #    for char in service.characteristics:
        #        if "read" in char.properties:
        #            try:
        #                value = await client.read_gatt_char(char.uuid)
        #                print(
        #                    "  [Characteristic] %s (%s), Value: %r",
        #                    char,
        #                    ",".join(char.properties),
        #                    value,
        #                )
        #            except Exception as e:
        #                print(
        #                    "  [Characteristic] %s (%s), Error: %s",
        #                    char,
        #                    ",".join(char.properties),
        #                    e,
        #                )

        #        else:
        #            print("  [Characteristic] %s (%s)", char, ",".join(char.properties))

        #        for descriptor in char.descriptors:
        #            try:
        #                value = await client.read_gatt_descriptor(descriptor.handle)
        #                print("    [Descriptor] %s, Value: %r", descriptor, value)
        #            except Exception as e:
        #                print("    [Descriptor] %s, Error: %s", descriptor, e)

        print("Connected: {0}".format(x))
        # ボタン状態の通知スタート
        await client.start_notify(
            BATTERY_CHARACTERISTIC_UUID, battery_notification_handler
        )
        await asyncio.sleep(1 * 60 * 60 * 1000)
        await client.stop_notify(BATTERY_CHARACTERISTIC_UUID)


if __name__ == "__main__":
    address = (
        # discovery.pyでみつけたtoio Core Cubeのデバイスアドレスをここにセットする
        "D0:8B:7F:12:34:56"  # Windows か Linux のときは16進6バイトのデバイスアドレスを指定
        if platform.system() != "Darwin"
        else MAC_ADDRESS  # macOSのときはmacOSのつけるUUID
    )
    loop = asyncio.get_event_loop()
    loop.run_until_complete(run(address, loop))
