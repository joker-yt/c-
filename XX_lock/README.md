# Lockguard

## Expected sequence

```
@startuml
main -> T1 : <<create>>
activate main
main -> main : prepare to start work
deactivate main

T1 -> T1 : check the status of the preparation

T1 -> T1 : work successfully!!!!

main -> main : join(T1)
destroy T1

@end uml
```

## T1 checked before main is ready(Ex1)
```
@startuml
main -> T1 : <<create>>
main -> main : prepare to start work
activate main
T1 -> T1 : check the status of the preparation
T1 -> T1 : not ready!!!! error!!!!!
note right
T1 should wait main's preparation
end note

deactivate main

main -> main : join(T1)
destroy T1

@end uml
```

## T1 is modified to wait, but fails to catch the notification from main.(Ex2)

```
@startuml
main -> T1 : <<create>>
main -> main : prepare to start work
activate main
deactivate main
main -> T1 : notify the ready status
====
T1 -> T1 : wait for main's notification (but missed!!!!)
note right
waiting forever....
end note
T1 -> T1 : check the status of the preparation


main -> main : join(T1)
note right
work couldn't been done forever.....
end note
@end uml
```

## Example of successful pattern(Ex3)
```
@startuml
main -> T1 : <<create>>
main -> main : prepare to start work
activate main
T1 -> T1 : wait for main's notification
activate T1
main -> T1 : notify the ready status
deactivate main
deactivate T1
T1 -> T1 : check the status of the preparation

T1 -> T1 : work successfully!!!!

main -> main : join(T1)
destroy T1

@end uml
```
