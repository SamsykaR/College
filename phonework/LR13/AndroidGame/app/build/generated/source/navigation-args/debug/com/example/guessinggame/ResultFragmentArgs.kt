package com.example.guessinggame

import android.os.Bundle
import androidx.lifecycle.SavedStateHandle
import androidx.navigation.NavArgs
import java.lang.IllegalArgumentException
import kotlin.String
import kotlin.jvm.JvmStatic

public data class ResultFragmentArgs(
  public val result: String,
) : NavArgs {
  public fun toBundle(): Bundle {
    val result = Bundle()
    result.putString("result", this.result)
    return result
  }

  public fun toSavedStateHandle(): SavedStateHandle {
    val result = SavedStateHandle()
    result.set("result", this.result)
    return result
  }

  public companion object {
    @JvmStatic
    public fun fromBundle(bundle: Bundle): ResultFragmentArgs {
      bundle.setClassLoader(ResultFragmentArgs::class.java.classLoader)
      val __result : String?
      if (bundle.containsKey("result")) {
        __result = bundle.getString("result")
        if (__result == null) {
          throw IllegalArgumentException("Argument \"result\" is marked as non-null but was passed a null value.")
        }
      } else {
        throw IllegalArgumentException("Required argument \"result\" is missing and does not have an android:defaultValue")
      }
      return ResultFragmentArgs(__result)
    }

    @JvmStatic
    public fun fromSavedStateHandle(savedStateHandle: SavedStateHandle): ResultFragmentArgs {
      val __result : String?
      if (savedStateHandle.contains("result")) {
        __result = savedStateHandle["result"]
        if (__result == null) {
          throw IllegalArgumentException("Argument \"result\" is marked as non-null but was passed a null value")
        }
      } else {
        throw IllegalArgumentException("Required argument \"result\" is missing and does not have an android:defaultValue")
      }
      return ResultFragmentArgs(__result)
    }
  }
}
