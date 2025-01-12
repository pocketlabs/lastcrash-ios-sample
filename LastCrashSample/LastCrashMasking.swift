import SwiftUI
import LastCrash

struct LastCrashMaskPositionValue: Equatable {
    let id: String
    let rect: CGRect
}

struct LastCrashMaskPositionKey: PreferenceKey {
    typealias Value = [LastCrashMaskPositionValue]
    static var defaultValue: [LastCrashMaskPositionValue] = []
    static func reduce(value: inout [LastCrashMaskPositionValue], nextValue: () -> [LastCrashMaskPositionValue]) {
        value.append(contentsOf: nextValue())
    }
}

struct LastCrashMask: View {
  let id: String
  init(_ id: String) { self.id = id }
  
  var body: some View {
    GeometryReader { metrics in
        let rect = metrics.frame(in: .global)

      Rectangle()
        .fill(Color.clear)
        .preference(
          key: LastCrashMaskPositionKey.self,
          value: [LastCrashMaskPositionValue(id: id, rect: rect)]
        )
    }
  }
}

let lastCrashOnPreferenceChange: ([LastCrashMaskPositionValue])->Void = {
    (preferences: [LastCrashMaskPositionValue]) -> Void in
    LastCrash.removeAllMaskRects()
    for p in preferences {
        LastCrash.addMaskRect(p.rect, maskId: p.id)
    }
}
